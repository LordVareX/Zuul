/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Written by Siqi.Wu <lion547016@gmail.com>, July 2021
 */

#include "SrpHelper.h"
#include "Misc/Base64.h"
#include "Misc/CString.h"
#include "Containers/UnrealString.h"

#include "CognitoIdpGlobals.h"

#if PLATFORM_WINDOWS
#include "Windows/WindowsPlatformCompilerPreSetup.h"
#include "Windows/WindowsHWrapper.h"
#include "Windows/AllowWindowsPlatformTypes.h"
#endif

#if PLATFORM_ANDROID
#include "Android/AndroidPlatformCompilerPreSetup.h"
#endif

#if PLATFORM_IOS
#include "IOS/IOSPlatformCompilerPreSetup.h"
#endif

#if PLATFORM_MAC
#include "Mac/MacPlatformCompilerPreSetup.h"
#endif

#if PLATFORM_APPLE
#include "Apple/ApplePlatformCompilerPreSetup.h"
#endif

#if PLATFORM_LINUX
#include "Linux/LinuxPlatformCompilerPreSetup.h"
#endif

#if PLATFORM_UNIX
#include "Unix/UnixPlatformCompilerPreSetup.h"
#endif

#define UI UI_ST
THIRD_PARTY_INCLUDES_START
#include "openssl/evp.h"
#include "openssl/sha.h"
#include "openssl/hmac.h"
#include "openssl/kdf.h"
#include "openssl/bio.h"

#include <iomanip>
#include <vector>
THIRD_PARTY_INCLUDES_END
#undef UI

#if PLATFORM_WINDOWS
#include "Windows/HideWindowsPlatformTypes.h"
#endif

static const std::string aws_secure_N = "FFFFFFFFFFFFFFFFC90FDAA22168C234C4C6628B80DC1CD1"
                                        "29024E088A67CC74020BBEA63B139B22514A08798E3404DD"
                                        "EF9519B3CD3A431B302B0A6DF25F14374FE1356D6D51C245"
                                        "E485B576625E7EC6F44C42E9A637ED6B0BFF5CB6F406B7ED"
                                        "EE386BFB5A899FA5AE9F24117C4B1FE649286651ECE45B3D"
                                        "C2007CB8A163BF0598DA48361C55D39A69163FA8FD24CF5F"
                                        "83655D23DCA3AD961C62F356208552BB9ED529077096966D"
                                        "670C354E4ABC9804F1746C08CA18217C32905E462E36CE3B"
                                        "E39E772C180E86039B2783A2EC07A28FB5C55DF06F4C52C9"
                                        "DE2BCBF6955817183995497CEA956AE515D2261898FA0510"
                                        "15728E5A8AAAC42DAD33170D04507A33A85521ABDF1CBA64"
                                        "ECFB850458DBEF0A8AEA71575D060C7DB3970F85A6E1E4C7"
                                        "ABF5AE8CDB0933D71E8C94E04A25619DCEE3D2261AD2EE6B"
                                        "F12FFA06D98A0864D87602733EC86A64521F2B18177B200C"
                                        "BBE117577A615D6C770988C0BAD946E208E24FA074E5AB31"
                                        "43DB5BFCE0FD108E4B82D120A93AD2CAFFFFFFFFFFFFFFFF";

static std::string
BinaryToHEXString(unsigned char* data, size_t bytes)
{
    std::stringstream ss;
    ss << std::hex;
    for (size_t i = 0; i < bytes / 2; ++i)
        ss << std::setw(2) << std::setfill('0') << (int)data[i];
    return ss.str();
}


static void
ConvertHEXStringToCharVector(const std::string &hex_str,
                             std::vector<unsigned char> &output)
{
    const size_t input_length = hex_str.size();
    const size_t output_length = (input_length+1) / 2;
    output.resize(output_length);

    for (unsigned int i = 0; i < input_length; i += 2)
    {
        std::string byteString = hex_str.substr(i, 2);
        char byte = (char)strtol(byteString.c_str(), nullptr, 16);
        output[(i / 2)] = byte;
    }

}

namespace
{
    struct BIOFreeAll { void operator()(BIO* p) { BIO_free_all(p); } };
}

static std::string
Base64Encode(const std::vector<unsigned char> &binary)
{
    std::unique_ptr<BIO, BIOFreeAll> b64(BIO_new(BIO_f_base64()));
    BIO_set_flags(b64.get(), BIO_FLAGS_BASE64_NO_NL);
    BIO* sink = BIO_new(BIO_s_mem());
    BIO_push(b64.get(), sink);
    BIO_write(b64.get(), binary.data(), int(binary.size()));
    BIO_flush(b64.get());
    const char* encoded;
    const long len = BIO_get_mem_data(sink, &encoded);
    return std::string(encoded, len);
}

// Assumes no newlines or extra characters in encoded string
static std::vector<unsigned char>
Base64Decode(const char* encoded)
{
    std::unique_ptr<BIO, BIOFreeAll> b64(BIO_new(BIO_f_base64()));
    BIO_set_flags(b64.get(), BIO_FLAGS_BASE64_NO_NL);
    BIO* source = BIO_new_mem_buf(encoded, -1); // read-only source
    BIO_push(b64.get(), source);
    const size_t maxlen = strlen(encoded) / 4 * 3 + 1;
    std::vector<unsigned char> decoded(maxlen);
    const int len = BIO_read(b64.get(), decoded.data(), int(maxlen));
    decoded.resize(len);
    return decoded;
}


static std::string
PadHexStringWithLeadingZero(const std::string &hex_string)
{
    std::string output;
    char top = hex_string[0];
    if ((hex_string.size() % 2) == 1)
        output = "0" + hex_string;
    else if (top == '8' || top == '9' || top == 'a' || top == 'b' || top == 'c' || top == 'd' || top == 'e' || top == 'f' || top == 'A' || top == 'B' || top == 'C' || top == 'D' || top == 'E' || top == 'F')
        output = "00" + hex_string;
    else
        output = hex_string;

    return output;
}


static std::vector<unsigned char>
PadCharVector(std::vector<unsigned char> &digest)
{
    std::vector<unsigned char> output;
    // convert to hex, pad then convert to unsigned char and output
    std::string hex_string = BinaryToHEXString(digest.data(), int(digest.size() * 2));
    hex_string = PadHexStringWithLeadingZero(hex_string);
    ConvertHEXStringToCharVector(hex_string, output);
    return output;
}

static void
DigestMessage(const std::vector<unsigned char> &message, std::vector<unsigned char> &digest)
{
    EVP_MD_CTX *mdctx = EVP_MD_CTX_create();
    EVP_DigestInit_ex(mdctx, EVP_sha256(), nullptr);
    EVP_DigestUpdate(mdctx, message.data(), message.size());
    digest.resize(EVP_MD_size(EVP_sha256()));
    unsigned int digest_len;
    EVP_DigestFinal_ex(mdctx, digest.data(), &digest_len);
    EVP_MD_CTX_destroy(mdctx);
}


static void
DigestMessage(const std::string &message, std::vector<unsigned char> &digest)
{
    EVP_MD_CTX *mdctx = EVP_MD_CTX_create();
    EVP_DigestInit_ex(mdctx, EVP_sha256(), nullptr);
    EVP_DigestUpdate(mdctx, message.c_str(), message.size());
    digest.resize(EVP_MD_size(EVP_sha256()));
    unsigned int digest_len;
    EVP_DigestFinal_ex(mdctx, digest.data(), &digest_len);
    EVP_MD_CTX_destroy(mdctx);
}


static void
HKDF(const std::vector<unsigned char> &salt,
     const std::vector<unsigned char> &secret,
     const std::vector<unsigned char> &label,
     std::vector<unsigned char> &output)
{
    EVP_PKEY_CTX *pctx;
    output.resize(16);
    size_t outlen = output.size();
    pctx = EVP_PKEY_CTX_new_id(EVP_PKEY_HKDF, nullptr);
    EVP_PKEY_derive_init(pctx);
    EVP_PKEY_CTX_set_hkdf_md(pctx, EVP_sha256());
    EVP_PKEY_CTX_set1_hkdf_salt(pctx, salt.data(), int(salt.size()));
    EVP_PKEY_CTX_set1_hkdf_key(pctx, secret.data(), int(secret.size()));
    EVP_PKEY_CTX_add1_hkdf_info(pctx, label.data(), int(label.size()));
    EVP_PKEY_derive(pctx, output.data(), &outlen);
}

USrpHelper::USrpHelper() :
        bn_N_(BN_new()),
        bn_g_(BN_new()),
        bn_k_(BN_new()),
        bn_a_(BN_new()),
        bn_A_(BN_new()),
        bn_random_password(BN_new()) {
    BN_hex2bn(&bn_N_, aws_secure_N.c_str());
    BN_hex2bn(&bn_g_, "2");
    
    std::vector<unsigned char> ng_block;
    ConvertHEXStringToCharVector("00" + aws_secure_N + "02", ng_block);

    std::vector<unsigned char> k_vector; // k actually seems to be fixed, shouldn't really need to regenerate all the time
    DigestMessage(ng_block, k_vector);
    BN_bin2bn(k_vector.data(), int(k_vector.size()), bn_k_);

    BN_rand(bn_a_, 1024, BN_RAND_TOP_ANY, BN_RAND_BOTTOM_ANY); // 1024-bit random word
}

USrpHelper::~USrpHelper() {
    BN_free(bn_N_);
    BN_free(bn_g_);
    BN_free(bn_k_);
    BN_free(bn_a_);
    BN_free(bn_A_);

    BN_free(bn_random_password);
}

FString USrpHelper::ComputeSRP_A() {
    if (BN_is_zero(bn_A_) != 1) {
        std::string srp_A = (BN_bn2hex(bn_A_));
        return srp_A.c_str();
    } else {
        BN_CTX * bn_ctx = BN_CTX_new();

        BN_mod_exp(bn_A_, bn_g_, bn_a_, bn_N_, bn_ctx);

        BIGNUM * bn_mod(BN_new());

        BN_mod(bn_mod, bn_A_, bn_N_, bn_ctx);

        if (BN_is_zero(bn_mod)) {
            LOG_COGNITOIDP_NORMAL("Illegal paramater. A mod N cannot be 0.");
        }

        BN_free(bn_mod);

        std::string srp_A = (BN_bn2hex(bn_A_));

        BN_CTX_free(bn_ctx);

        return srp_A.c_str();
    }
}

FString USrpHelper::ComputePasswordVerifier(FString &SALT, FString &RandomPassword, FString DeviceGroupKey, FString DeviceKey) {
    BN_rand(bn_random_password, 320, BN_RAND_TOP_ANY, BN_RAND_BOTTOM_ANY); // 40 bytes random word

    std::vector<unsigned char> random_password;
    ConvertHEXStringToCharVector(BN_bn2hex(bn_random_password), random_password);

    RandomPassword = Base64Encode(random_password).c_str();

    const std::string FULL_PASSWORD = std::string(TCHAR_TO_UTF8(*DeviceGroupKey)) + std::string(TCHAR_TO_UTF8(*DeviceKey)) + ":" + Base64Encode(random_password);
    std::vector<unsigned char> userid_digest;
    DigestMessage(FULL_PASSWORD, userid_digest);

    BIGNUM * bn_random_ = BN_new();
    BN_rand(bn_random_, 128, BN_RAND_TOP_ANY, BN_RAND_BOTTOM_ANY); // 128-bit random word

    std::string salt = PadHexStringWithLeadingZero(BN_bn2hex(bn_random_));

    std::vector<unsigned char> salt_array;
    ConvertHEXStringToCharVector(salt, salt_array);

    SALT = Base64Encode(salt_array).c_str();

    std::vector<unsigned char> x_array(salt_array.size() + userid_digest.size());
    std::vector<unsigned char> x_digest;
    std::copy(salt_array.begin(), salt_array.end(), x_array.begin());
    std::copy(userid_digest.begin(), userid_digest.end(), x_array.begin() + salt_array.size());
    DigestMessage(x_array, x_digest);
    x_digest = PadCharVector(x_digest);

    BIGNUM * bn_x(BN_new());

    BN_bin2bn(x_digest.data(), int(x_digest.size()), bn_x);

    BIGNUM * bn_password_verifier(BN_new());

    BN_CTX * bn_ctx = BN_CTX_new();

    BN_mod_exp(bn_password_verifier, bn_g_, bn_x, bn_N_, bn_ctx);

    std::string password_verifier = PadHexStringWithLeadingZero(BN_bn2hex(bn_password_verifier));

    BN_CTX_free(bn_ctx);

    BN_free(bn_password_verifier);
    BN_free(bn_x);
    BN_free(bn_random_);

    std::vector<unsigned char> password_verifier_array;
    ConvertHEXStringToCharVector(password_verifier, password_verifier_array);

    return Base64Encode(password_verifier_array).c_str();
}

FString USrpHelper::GetRandomPassword() {
    std::vector<unsigned char> random_password;
    ConvertHEXStringToCharVector(BN_bn2hex(bn_random_password), random_password);

    return Base64Encode(random_password).c_str();
}

FString USrpHelper::ComputePasswordClaimSignature(FString SECRET_BLOCK, FString SALT, FString SRP_B, FDateTime time, FString &timestamp, FString GroupKey, FString Key, FString password) {
    std::string srp_A_string_pad = PadHexStringWithLeadingZero(BN_bn2hex(bn_A_));
    std::string srp_b_string_pad = PadHexStringWithLeadingZero(TCHAR_TO_UTF8(*SRP_B));
    std::string u = srp_A_string_pad + srp_b_string_pad;

    std::vector<unsigned char> array_srp_A_srp_b, u_digest;
    ConvertHEXStringToCharVector(u, array_srp_A_srp_b);
    DigestMessage(array_srp_A_srp_b, u_digest);
    u_digest = PadCharVector(u_digest);

    const std::string FULL_PASSWORD = std::string(TCHAR_TO_UTF8(*GroupKey)) + std::string(TCHAR_TO_UTF8(*Key)) + ":" + std::string(TCHAR_TO_UTF8(*password));
    std::vector<unsigned char> userid_digest;
    DigestMessage(FULL_PASSWORD, userid_digest);

    std::vector<unsigned char> salt_array;
    ConvertHEXStringToCharVector(PadHexStringWithLeadingZero(TCHAR_TO_UTF8(*SALT)), salt_array);

    std::vector<unsigned char> x_array(salt_array.size() + userid_digest.size());
    std::vector<unsigned char> x_digest;
    std::copy(salt_array.begin(), salt_array.end(), x_array.begin());
    std::copy(userid_digest.begin(), userid_digest.end(), x_array.begin() + salt_array.size());
    DigestMessage(x_array, x_digest);

    BIGNUM * bn_x(BN_new());
    BIGNUM * bn_u(BN_new());
    BIGNUM * bn_srp_B(BN_new());

    BN_bin2bn(x_digest.data(), int(x_digest.size()), bn_x);
    BN_bin2bn(u_digest.data(), int(u_digest.size()), bn_u);
    BN_hex2bn(&bn_srp_B, TCHAR_TO_UTF8(*SRP_B));

    BN_CTX * bn_ctx = BN_CTX_new();

    BIGNUM * bn_b_mod_(BN_new());
    BN_mod(bn_b_mod_, bn_srp_B, bn_N_, bn_ctx);

    if (BN_is_zero(bn_b_mod_) == 1) {
        LOG_COGNITOIDP_NORMAL("B cannot be zero.");
    }

    if (BN_is_zero(bn_u) == 1) {
        LOG_COGNITOIDP_NORMAL("U cannot be zero.");
    }

    BIGNUM * bn_g_mod_pow_xn(BN_new());
    BIGNUM * bn_k_mult(BN_new());
    BIGNUM * bn_b_sub(BN_new());
    BIGNUM * bn_u_x(BN_new());
    BIGNUM * bn_a_add(BN_new());
    BIGNUM * bn_b_sub_modpow(BN_new());
    BIGNUM * bn_S(BN_new());

    BN_mod_exp(bn_g_mod_pow_xn, bn_g_, bn_x, bn_N_, bn_ctx);
    BN_mul(bn_k_mult, bn_k_, bn_g_mod_pow_xn, bn_ctx);
    BN_sub(bn_b_sub, bn_srp_B, bn_k_mult);

    BN_mul(bn_u_x, bn_u, bn_x, bn_ctx);
    BN_add(bn_a_add, bn_a_, bn_u_x);
    BN_mod_exp(bn_b_sub_modpow, bn_b_sub, bn_a_add, bn_N_, bn_ctx);

    BN_mod(bn_S, bn_b_sub_modpow, bn_N_, bn_ctx);

    const std::string hex_s = std::string(BN_bn2hex(bn_S));
    std::vector<unsigned char> s_char;
    ConvertHEXStringToCharVector(hex_s, s_char);
    s_char = PadCharVector(s_char);

    const std::string dervied_key_info_str = "Caldera Derived Key";
    std::vector<unsigned char> dervied_key_info(dervied_key_info_str.begin(), dervied_key_info_str.end());

    // now get the hashed key
    std::vector<unsigned char> key;
    HKDF(u_digest, s_char, dervied_key_info, key);

    BN_free(bn_x);
    BN_free(bn_u);
    BN_free(bn_srp_B);

    BN_free(bn_g_mod_pow_xn);
    BN_free(bn_k_mult);
    BN_free(bn_b_sub);
    BN_free(bn_u_x);
    BN_free(bn_a_add);
    BN_free(bn_b_sub_modpow);
    BN_free(bn_S);

    BN_CTX_free(bn_ctx);

    std::vector<unsigned char> secret_block_char;
    secret_block_char = Base64Decode(TCHAR_TO_UTF8(*SECRET_BLOCK));

    {
        FString DayStr;
        FString MonthStr;

        switch (time.GetDayOfWeek())
        {
            case EDayOfWeek::Monday:	DayStr = TEXT("Mon");	break;
            case EDayOfWeek::Tuesday:	DayStr = TEXT("Tue");	break;
            case EDayOfWeek::Wednesday:	DayStr = TEXT("Wed");	break;
            case EDayOfWeek::Thursday:	DayStr = TEXT("Thu");	break;
            case EDayOfWeek::Friday:	DayStr = TEXT("Fri");	break;
            case EDayOfWeek::Saturday:	DayStr = TEXT("Sat");	break;
            case EDayOfWeek::Sunday:	DayStr = TEXT("Sun");	break;
        }

        switch (time.GetMonthOfYear())
        {
            case EMonthOfYear::January:		MonthStr = TEXT("Jan");	break;
            case EMonthOfYear::February:	MonthStr = TEXT("Feb");	break;
            case EMonthOfYear::March:		MonthStr = TEXT("Mar");	break;
            case EMonthOfYear::April:		MonthStr = TEXT("Apr");	break;
            case EMonthOfYear::May:			MonthStr = TEXT("May");	break;
            case EMonthOfYear::June:		MonthStr = TEXT("Jun");	break;
            case EMonthOfYear::July:		MonthStr = TEXT("Jul");	break;
            case EMonthOfYear::August:		MonthStr = TEXT("Aug");	break;
            case EMonthOfYear::September:	MonthStr = TEXT("Sep");	break;
            case EMonthOfYear::October:		MonthStr = TEXT("Oct");	break;
            case EMonthOfYear::November:	MonthStr = TEXT("Nov");	break;
            case EMonthOfYear::December:	MonthStr = TEXT("Dec");	break;
        }

        FString Time = FString::Printf(TEXT("%02i:%02i:%02i"), time.GetHour(), time.GetMinute(), time.GetSecond());
        timestamp = FString::Printf(TEXT("%s %s %d %s UTC %d"), *DayStr, *MonthStr, time.GetDay(), *Time, time.GetYear());
    }

    std::string time_str = TCHAR_TO_UTF8(*timestamp);
    std::string group_key_string = TCHAR_TO_UTF8(*GroupKey);
    std::string key_string = TCHAR_TO_UTF8(*Key);

    std::vector<unsigned char> content(group_key_string.size() + key_string.size() + secret_block_char.size() + time_str.size());
    std::copy(group_key_string.begin(), group_key_string.end(), content.begin());
    std::copy(key_string.begin(), key_string.end(), content.begin() + group_key_string.size());
    std::copy(secret_block_char.begin(), secret_block_char.end(), content.begin() + group_key_string.size() + key_string.size());
    std::copy(time_str.begin(), time_str.end(), content.begin() + group_key_string.size() + key_string.size() + secret_block_char.size());

    std::vector<unsigned char> hmac(32); // sha256 will make produce a 32 byte array
    HMAC(EVP_sha256(), key.data(), int(key.size()), content.data(), int(content.size()), hmac.data(), nullptr);

    std::string claim = Base64Encode(hmac);

    return claim.c_str();
}
