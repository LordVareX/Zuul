// Copyright Pandores Marketplace 2023. All Rights Reserved.

#include "EmailLibrary.h"
#include "EasyEmail.h"
#include "Email.h"
#include "UObject/Class.h"
#include "UObject/Package.h"

const FString UEmailLibrary::DefaultMimeType = TEXT("application/octet-stream");

FString UEmailLibrary::GetMimeTypeFromFileName(const FString& FileName)
{
	FString Extension;

	if (!FileName.Split(TEXT("."), nullptr, &Extension, ESearchCase::CaseSensitive, ESearchDir::FromEnd))
	{
		UE_LOG(LogEasyEmail, Warning, TEXT("GetMimeTypeFromFileName: File %s doesn't have a proper extension. Using \"%s\"."), *FileName, *DefaultMimeType);
		return DefaultMimeType;
	}

#define ADD_TYPE(e, n) {TEXT( e ), TEXT( n )}
	static const TMap<FString, FString> SupportedTypes =
	{
		ADD_TYPE("aac",		"audio/aac"),
		ADD_TYPE("abw",		"application/x-abiword"),
		ADD_TYPE("arc",		"application/x-freearc"),
		ADD_TYPE("avi",		"video/x-msvideo"),
		ADD_TYPE("azw",		"application/vnd"),
		ADD_TYPE("bin",		"application/octet-stream"),
		ADD_TYPE("bmp",		"image/bmp"),
		ADD_TYPE("bz",		"application/x-bzip"),
		ADD_TYPE("bz2",		"application/x-bzip2"),
		ADD_TYPE("csh",		"application/x-csh"),
		ADD_TYPE("css",		"text/css"),
		ADD_TYPE("csv",		"text/csv"),
		ADD_TYPE("doc",		"application/msword"),
		ADD_TYPE("docx",	"application/vnd"),
		ADD_TYPE("eot",		"application/vnd"),
		ADD_TYPE("epub",	"application/epub+zip"),
		ADD_TYPE("gz",		"application/gzip"),
		ADD_TYPE("gif",		"image/gif"),
		ADD_TYPE("htm",		"text/html"),
		ADD_TYPE("html",	"text/html"),
		ADD_TYPE("ico",		"image/vnd"),
		ADD_TYPE("ics",		"text/calendar"),
		ADD_TYPE("jar",		"application/java-archive"),
		ADD_TYPE("jpeg",	"image/jpeg"),
		ADD_TYPE("jpg",		"image/jpeg"),
		ADD_TYPE("js",		"text/javascript"),
		ADD_TYPE("json",	"application/json"),
		ADD_TYPE("jsonld",	"application/ld+json"),
		ADD_TYPE("mid",		"audio/midi"),
		ADD_TYPE("mjs",		"text/javascript"),
		ADD_TYPE("mp3",		"audio/mpeg"),
		ADD_TYPE("mpeg",	"video/mpeg"),
		ADD_TYPE("mpkg",	"application/vnd"),
		ADD_TYPE("odp",		"application/vnd"),
		ADD_TYPE("ods",		"application/vnd"),
		ADD_TYPE("odt",		"application/vnd"),
		ADD_TYPE("oga",		"audio/ogg"),
		ADD_TYPE("ogv",		"video/ogg"),
		ADD_TYPE("ogx",		"application/ogg"),
		ADD_TYPE("opus",	"audio/opus"),
		ADD_TYPE("otf",		"font/otf"),
		ADD_TYPE("png",		"image/png"),
		ADD_TYPE("pdf",		"application/pdf"),
		ADD_TYPE("php",		"application/x-httpd-php"),
		ADD_TYPE("ppt",		"application/vnd"),
		ADD_TYPE("pptx",	"application/vnd"),
		ADD_TYPE("rar",		"application/vnd"),
		ADD_TYPE("rtf",		"application/rtf"),
		ADD_TYPE("sh",		"application/x-sh"),
		ADD_TYPE("svg",		"image/svg+xml"),
		ADD_TYPE("swf",		"application/x-shockwave-flash"),
		ADD_TYPE("tar",		"application/x-tar"),
		ADD_TYPE("tif",		"image/tiff"),
		ADD_TYPE("ts",		"video/mp2t"),
		ADD_TYPE("ttf",		"font/ttf"),
		ADD_TYPE("txt",		"text/plain"),
		ADD_TYPE("vsd",		"application/vnd"),
		ADD_TYPE("wav",		"audio/wav"),
		ADD_TYPE("weba",	"audio/webm"),
		ADD_TYPE("webm",	"video/webm"),
		ADD_TYPE("webp",	"image/webp"),
		ADD_TYPE("woff",	"font/woff"),
		ADD_TYPE("woff2",	"font/woff2"),
		ADD_TYPE("xhtml",	"application/xhtml+xml"),
		ADD_TYPE("xls",		"application/vnd"),
		ADD_TYPE("xlsx",	"application/vnd"),
		ADD_TYPE("xml",		"application/xml"),
		ADD_TYPE("xul",		"application/vnd"),
		ADD_TYPE("zip",		"application/zip"),
		ADD_TYPE("3gp",		"video/3gpp"),
		ADD_TYPE("3g2",		"video/3gpp2"),
		ADD_TYPE("7z",		"application/x-7z-compressed")
	};
#undef ADD_TYPE

	const FString* const MimeType = SupportedTypes.Find(Extension);

	if (!MimeType)
	{
		UE_LOG(LogEasyEmail, Warning, TEXT("GetMimeTypeFromFileName: Unrecognized extension \".%s\". Using default MIME-Type \"%s\"."), *Extension, *DefaultMimeType);
		return DefaultMimeType;
	}

	return *MimeType;
}

FString UEmailLibrary::SmtpConnectionTypeEnumToString(const ESmtpConnectionType Connection)
{
	switch (Connection)
	{
	case ESmtpConnectionType::NoEncryption: return TEXT("NoEncryption");
	case ESmtpConnectionType::SSL:			return TEXT("SSL");
	case ESmtpConnectionType::StartTLS:		return TEXT("StartTLS");
	}

	return TEXT("UNDEFINED");
}

FString UEmailLibrary::ContentEncodingTransfertEnumToString(const EContentTransfertEncoding Encoding)
{
	switch (Encoding)
	{
	case EContentTransfertEncoding::BASE64:				return TEXT("BASE64");
	case EContentTransfertEncoding::QUOTED_PRINTABLE:	return TEXT("QUOTED-PRINTABLE");
	case EContentTransfertEncoding::_8BIT:				return TEXT("8BIT");
	case EContentTransfertEncoding::_7BIT:				return TEXT("7BIT");
	case EContentTransfertEncoding::BINARY:				return TEXT("BINARY");
	case EContentTransfertEncoding::xtoken:				return TEXT("x-token");
	}

	// Lower-case to identify the fallback.
	return TEXT("binary");
}

FString UEmailLibrary::EmailCharsetEnumToString(const EEmailCharset Charset)
{
	static const TArray<FString> Values =
	{
		TEXT("big5"),			
		TEXT("euc-kr"),			
		TEXT("iso-8859-1"),		
		TEXT("iso-8859-2"),		
		TEXT("iso-8859-3"),		
		TEXT("iso-8859-4"),		
		TEXT("iso-8859-5"),		
		TEXT("iso-8859-6"),		
		TEXT("iso-8859-7"),		
		TEXT("iso-8859-8"),		
		TEXT("koi8-r"),			
		TEXT("shift-jis"),		
		TEXT("x-euc"),			
		TEXT("utf-8"),			
		TEXT("windows-1250"),	
		TEXT("windows-1251"),	
		TEXT("windows-1252"),	
		TEXT("windows-1253"),	
		TEXT("windows-1254"),	
		TEXT("windows-1255"),	
		TEXT("windows-1256"),	
		TEXT("windows-1257"),	
		TEXT("windows-1258"),	
		TEXT("windows-874")	
	};

	return Values.IsValidIndex((int32)Charset) ? Values[(int32)Charset] : TEXT("utf-8");
}

FString UEmailLibrary::FormatSmtpResponse(const FString& Response)
{
	return Response.Replace(TEXT("\n"), TEXT("<CR>")).Replace(TEXT("\r"), TEXT("<LF>"));
}

FString UEmailLibrary::GetGmailSmtpAddress() 
{
	return TEXT("smtp.gmail.com");
}

FString UEmailLibrary::GetOutlookSmtpAddress()
{
	return TEXT("smtp.live.com");
}

FString UEmailLibrary::GetOffice365SmtpAddress()
{
	return TEXT("smtp.office365.com");
}

FString UEmailLibrary::GetYahooEmailSmtpAddress()
{
	return TEXT("smtp.mail.yahoo.com");
}

FString UEmailLibrary::GetHotmailSmtpAddress()
{
	return TEXT("smtp.live.com");
}

int32 UEmailLibrary::GetDefaultPortForConnection(const ESmtpConnectionType Connection)
{
	switch (Connection)
	{
	case ESmtpConnectionType::NoEncryption: return 25;
	case ESmtpConnectionType::SSL:			return 465;
	case ESmtpConnectionType::StartTLS:		return 587;
	}

	return 0;
}
