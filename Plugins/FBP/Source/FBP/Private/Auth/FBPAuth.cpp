// Copyright (c) 2022 King Wai Mark



#include "Auth/FBPAuth.h"


firebase::auth::Auth* UFBPAuth::Auth = nullptr;


firebase::auth::Auth* UFBPAuth::FBPGetAuth()
{
	firebase::App* App = UFBPApp::FBPGet();
	if(UFBPAuth::Auth == nullptr && App != nullptr)
	{
		UFBPAuth::Auth = firebase::auth::Auth::GetAuth(App);
	}
	return UFBPAuth::Auth;
}

bool UFBPAuth::FBPUserIsSignedIn()
{
	return FBPGetAuth() != nullptr && FBPGetAuth()->current_user() != nullptr;
}

bool UFBPAuth::FBPCheckIfEmailIsVerified()
{
	if(UFBPAuth::FBPUserIsSignedIn())
	{
		return FBPGetAuth()->current_user()->is_email_verified();
	}
	else
	{
		return false;	
	}
}

void UFBPAuth::FBPCreateAccountWithEmailAndPassword(FString Email, FString Password,
                                                    const FOnAccountCreateSuccess& OnSuccess, const FOnAccountCreateFail& OnFail)
{
	firebase::auth::Auth* AuthRef = FBPGetAuth();
	if(UFBPFileUtilities::HasGoogleFile)
	{
		AuthRef->CreateUserWithEmailAndPassword(TCHAR_TO_UTF8(*Email), TCHAR_TO_UTF8(*Password))
				.OnCompletion([OnSuccess, OnFail](const ::firebase::Future<::firebase::auth::User *> &Result)
				{
					const firebase::auth::User* User = *Result.result();
					if(User)
					{
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
						OnSuccess.ExecuteIfBound(FBPUser);
					} else
					{
						OnFail.ExecuteIfBound(FString(Result.error_message()));
					}
				});
	}
	
}

void UFBPAuth::FBPSignInWithEmailAndPassword(FString Email, FString Password, const FOnSignInSuccess& OnSuccess,
	const FOnSignInFail& OnFail)
{
	firebase::auth::Auth* AuthRef = FBPGetAuth();
	if(UFBPFileUtilities::HasGoogleFile)
	{
		AuthRef->SignInWithEmailAndPassword(TCHAR_TO_UTF8(*Email), TCHAR_TO_UTF8(*Password))
		.OnCompletion([OnSuccess, OnFail](const ::firebase::Future<::firebase::auth::User *> &Result)
		{
				const firebase::auth::User* User = *Result.result();
				if(User)
				{
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
					OnSuccess.ExecuteIfBound(FBPUser);
				} else
				{
					OnFail.ExecuteIfBound(FString(Result.error_message()));
				}
		});
	}
	

}

void UFBPAuth::FBPSignOut()
{
	if(UFBPAuth::FBPUserIsSignedIn())
	{
		FBPGetAuth()->SignOut();
	}
	
}



void UFBPAuth::FBPListenForSignInChanges(const FOnSignedIn& OnSignedIn, const FOnSignedOut& OnSignedOut)
{
	firebase::auth::Auth* AuthRef = FBPGetAuth();
	if(UFBPFileUtilities::HasGoogleFile)
	{
		AuthRef->AddAuthStateListener(new FBPAuthStateListener(OnSignedIn, OnSignedOut));
	}
	
}

 
void UFBPAuth::FBPSendVerificationEmail(const FOnVerificationEmailSent& OnVerificationEmailSent,
	const FOnFailToSendVerificationEmail& OnFailToSendVerificationEmail)
{
	firebase::auth::Auth* AuthRef = FBPGetAuth();
	if(UFBPFileUtilities::HasGoogleFile)
	{
		if(UFBPAuth::FBPUserIsSignedIn())
		{
			AuthRef->current_user()->SendEmailVerification().OnCompletion([OnVerificationEmailSent, OnFailToSendVerificationEmail](const firebase::Future<void>& Result)
			{
				if(Result.error())
				{
					OnFailToSendVerificationEmail.ExecuteIfBound(FString(Result.error_message()));
				}
				else
				{
					OnVerificationEmailSent.ExecuteIfBound();
				}
			});
		}
	}
	

}

void UFBPAuth::FBPSendPasswordResetEmail(const FString Email, const FOnPasswordResetEmailSent& OnPasswordResetEmailSent,
	const FOnFailToSendPasswordResetEmail& OnFailToSendPasswordResetEmail)
{
	firebase::auth::Auth* AuthRef = FBPGetAuth();
	if(UFBPFileUtilities::HasGoogleFile)
	{
		AuthRef->SendPasswordResetEmail(TCHAR_TO_UTF8(*Email)).OnCompletion([Email, OnPasswordResetEmailSent, OnFailToSendPasswordResetEmail](const firebase::Future<void>& Result)
			{

				if(Result.error())
				{
					OnFailToSendPasswordResetEmail.ExecuteIfBound(FString(Result.error_message()));
				}
				else
				{
					OnPasswordResetEmailSent.ExecuteIfBound(Email);
				}
			});
	}
	
}


void UFBPAuth::FBPSignInAnonymously(const FOnSignInSuccess& OnSuccess, const FOnSignInFail& OnFail)
{
	firebase::auth::Auth* AuthRef = FBPGetAuth();
	if(UFBPFileUtilities::HasGoogleFile)
	{
		AuthRef->SignInAnonymously()
		.OnCompletion([OnSuccess, OnFail](const ::firebase::Future<::firebase::auth::User *> &Result)
			{
					const firebase::auth::User* User = *Result.result();
					if(User)
					{
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
						OnSuccess.ExecuteIfBound(FBPUser);
					} else
					{
						OnFail.ExecuteIfBound(FString(Result.error_message()));
					}
			});
	}

}



