// Copyright (c) 2022 King Wai Mark

#pragma once



#include "FBPFirebaseUser.h"
#include "FBPApp.h"

#if PLATFORM_WINDOWS || PLATFORM_MAC || PLATFORM_ANDROID || PLATFORM_IOS
	#include "firebase/auth.h"
#endif


#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FBPAuth.generated.h"


// FBPCreateAccountWithEmailAndPassword
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnAccountCreateSuccess, FBPFirebaseUser, FirebaseUser);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnAccountCreateFail, FString, ErrorMessage);
// FBPSignInWithEmailAndPassword
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnSignInSuccess, FBPFirebaseUser, FirebaseUser);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnSignInFail, FString, ErrorMessage);
// FBPListenForSignInChanges
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnSignedIn, FBPFirebaseUser, FirebaseUser);
DECLARE_DYNAMIC_DELEGATE(FOnSignedOut);
// FBPSendVerificationEmail
DECLARE_DYNAMIC_DELEGATE(FOnVerificationEmailSent);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnFailToSendVerificationEmail, FString, ErrorMessage);
// FBPSendPasswordResetEmail
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnPasswordResetEmailSent, FString, Email);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnFailToSendPasswordResetEmail, FString, ErrorMessage);

/**
 * @author King Wai Mark
 *
 * This class contains functions to manipulate the Authentication part of Firebase.
 */
UCLASS()
class FBP_API UFBPAuth : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()


	static firebase::auth::Auth* Auth;
	static firebase::auth::Auth* FBPGetAuth();
	/**
	 * Checks to see if the a user is signed in.
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "User Is Signed In", Keywords="User Is Signed In"), Category = "Authentication - Firebase Plugin By KWM")
	static bool FBPUserIsSignedIn();
	/**
	 * Checks to see if the user verified their email.
	 * There must be a user that is signed into the app. Otherwise, it will return false.
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Check If Email Is Verified", Keywords="Check If Email Is Verified"), Category = "Authentication - Firebase Plugin By KWM")
	static bool FBPCheckIfEmailIsVerified();
	/**
	 * Creates a user account by providing an email and password.
	 *
	 * Delegates used:
	 *		DECLARE_DYNAMIC_DELEGATE_OneParam(FOnAccountCreateSuccess, FBPFirebaseUser, FirebaseUser);
	 *		DECLARE_DYNAMIC_DELEGATE_OneParam(FOnAccountCreateFail, FString, ErrorMessage);
	 * 
	 * @param Email Email used to create the account
	 * @param Password Password used for the account
	 * @param OnSuccess Executes when the function completes and successfully creates the account.
	 * @param OnFail Executes when the function completes and it failed to create the account.
	 *
	 * @author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Create Account with Email & Password", Keywords = "Create Account with Email & Password"), Category = "Authentication - Firebase Plugin By KWM")
	static void FBPCreateAccountWithEmailAndPassword(FString Email, FString Password, const FOnAccountCreateSuccess& OnSuccess, const FOnAccountCreateFail& OnFail);

	/**
	 * Sign in by providing an email and password in Firebase Authentication.
	 *
	 * Delegates used:
	 *		DECLARE_DYNAMIC_DELEGATE_OneParam(FOnSignInSuccess, FBPFirebaseUser, FirebaseUser);
	 *		DECLARE_DYNAMIC_DELEGATE_OneParam(FOnSignInFail, FString, ErrorMessage);
	 * 
	 * @param Email Email 
	 * @param Password Password to the account
	 * @param OnSuccess Executes when the function completes and successfully signed in.
	 * @param OnFail Executes when the function completes but failed to sign in.
	 *
	 * @author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Sign In With Email and Password", Keywords = "Sign In With Email and Password"), Category = "Authentication - Firebase Plugin By KWM")
	static void FBPSignInWithEmailAndPassword(FString Email, FString Password, const FOnSignInSuccess& OnSuccess, const FOnSignInFail& OnFail);


	/**
	 * Sign out of the Firebase app.
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Sign Out", Keywords = "Sign out"), Category = "Authentication - Firebase Plugin By KWM")
	static void FBPSignOut();

	/**
	 * Detects when a user signs in or out.
	 *
	 * Delegates used:
	 *		DECLARE_DYNAMIC_DELEGATE(FOnSignInSuccess);
	 *		DECLARE_DYNAMIC_DELEGATE_OneParam(FOnSignInFail, FString, ErrorMessage);
	 *
	 *	@param OnSignedIn Callback that will be called on a successful sign in
	 *	@param OnSignedOut Callback that will be called on a successful sign out
	 *
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Listen For Sign In Changes", Keywords = "Listen For Sign In Changes"), Category = "Authentication - Firebase Plugin By KWM")
	static void FBPListenForSignInChanges(const FOnSignedIn& OnSignedIn, const FOnSignedOut& OnSignedOut);


	/**
	 * Sends a verification email to the current signed in user.
	 *
	 * Delegates used:
	 *		DECLARE_DYNAMIC_DELEGATE(FOnVerificationEmailSent);
	 *		DECLARE_DYNAMIC_DELEGATE_OneParam(FOnFailToSendVerificationEmail, FString, ErrorMessage);
	 *	
	 *  @param OnVerificationEmailSent Callback that will be called when the verification email is sent successfully
	 *  @param OnFailToSendVerificationEmail Callback that will be called when it fails to send the verification email 
	 *
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Send Verification Email", Keywords = "Send Verification Email"), Category = "Authentication - Firebase Plugin By KWM")
	static void FBPSendVerificationEmail(const FOnVerificationEmailSent& OnVerificationEmailSent, const FOnFailToSendVerificationEmail& OnFailToSendVerificationEmail);

	/**
	 * Sends a password reset email by providing an email. The email must belong to a user in Firebase.
	 *
	 * Delegates used:
	 *		DECLARE_DYNAMIC_DELEGATE_OneParam(FOnPasswordResetEmailSent, FString, Email);
	 *		DECLARE_DYNAMIC_DELEGATE_OneParam(FOnFailToSendPasswordResetEmail, FString, ErrorMessage);
	 *
	 *	@param Email Email to send the password reset email to. Must be an email that is in Firebase.
	 *	@param OnPasswordResetEmailSent Callback that will be called when the password reset email is sent.
	 *	@param OnFailToSendPasswordResetEmail Callback that will be called when it fails to send the password reset email to the email provided.
	 *
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Send Password Reset Email", Keywords = "Send Password Reset Email"), Category = "Authentication - Firebase Plugin By KWM")
	static void FBPSendPasswordResetEmail(const FString Email, const FOnPasswordResetEmailSent& OnPasswordResetEmailSent, const FOnFailToSendPasswordResetEmail& OnFailToSendPasswordResetEmail);

	/**
	 *	Sign in anonymously without providing any login credentials.
	 *
	 * Delegates used:
	 *		DECLARE_DYNAMIC_DELEGATE_OneParam(FOnSignInSuccess, FBPFirebaseUser, FirebaseUser);
	 *		DECLARE_DYNAMIC_DELEGATE_OneParam(FOnSignInFail, FString, ErrorMessage);
	 * 
	 * @param OnSuccess Executes when the function completes and successfully signed in.
	 * @param OnFail Executes when the function completes but failed to sign in.
	 *
	 * @author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Sign In Anonymously", Keywords = "Sign In Anonymously"), Category = "Authentication - Firebase Plugin By KWM")
	static void FBPSignInAnonymously(const FOnSignInSuccess& OnSuccess, const FOnSignInFail& OnFail);
};




/**
 *	@author King Wai Mark
 *
 * This class is used in conjunction with FBPListenForSignInChanges to listen to sign in changes.
 * 
 * Delegates used:
 *		DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnSignedIn, FBPFirebaseUser, FirebaseUser);
 *		DECLARE_DYNAMIC_DELEGATE(FOnSignedOut);
 * 
 */
class FBPAuthStateListener : public firebase::auth::AuthStateListener
{
	
private:
	FOnSignedIn OnSignedIn;
	FOnSignedOut OnSignedOut;
	
public:
	FBPAuthStateListener(const FOnSignedIn OnSignedIn, const FOnSignedOut OnSignedOut)
	{
		this->OnSignedIn = OnSignedIn;
		this->OnSignedOut = OnSignedOut;
	}
	
	virtual void OnAuthStateChanged(firebase::auth::Auth* auth) override {
		firebase::auth::User* User = auth->current_user();
		if (User != nullptr) {
			FBPFirebaseUser FBPUser = FBPFirebaseUser();
			FBPUser.Uid = FString(User->uid().c_str());
			FBPUser.Email = FString(User->email().c_str());
			FBPUser.PhoneNumber = FString(User->phone_number().c_str());
			FBPUser.PhotoUrl = FString(User->photo_url().c_str());
			FBPUser.ProviderId = FString(User->provider_id().c_str());
			FBPUser.IsEmailVerified = User->is_email_verified();
			FBPUser.CreationTimestamp = User->metadata().creation_timestamp;
			FBPUser.LastSignedIn = User->metadata().last_sign_in_timestamp;
			FBPUser.IsAnonymous = User->is_anonymous();
			this->OnSignedIn.ExecuteIfBound(FBPUser);
		} else {
			this->OnSignedOut.ExecuteIfBound();
		}
	}
	
};