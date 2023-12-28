//Copyright (c) 2023 Betide Studio. All Rights Reserved.

#include "EIK_BlueprintFunctions.h"
#include "Engine/GameInstance.h"
#include "Containers/Array.h"
#include "GameFramework/GameModeBase.h"
#include "Misc/Base64.h"
#include "OnlineSubsystemEIK/AsyncFunctions/Login/EIK_Login_AsyncFunction.h"

FString UEIK_BlueprintFunctions::GetEpicAccountId(UObject* Context)
{
	if(Context)
	{
		if(!Context->GetWorld())
		{
			return FString();
		}
		if(const IOnlineSubsystem *SubsystemRef = IOnlineSubsystem::Get())
		{
			if(const IOnlineIdentityPtr IdentityPointerRef = SubsystemRef->GetIdentityInterface())
			{
				if(const TSharedPtr<const FUniqueNetId> EIK_NetID = UGameplayStatics::GetGameInstance(Context->GetWorld())->GetFirstGamePlayer()->GetPreferredUniqueNetId().GetUniqueNetId())
				{
					const FString String_UserID = EIK_NetID.Get()->ToString();
					TArray<FString> Substrings;
					String_UserID.ParseIntoArray(Substrings, TEXT("|"));
					// Check if the split was successful
					if (Substrings.Num() == 2)
					{
						return Substrings[0];
					}
					else
					{
						return FString();
					}
				}
				else
				{
					return FString();
				}
			}
			else
			{
				return FString();
			}
		}
		else
		{
			return FString();
		}
	}
	else
	{
		return FString();
	}
}

FString UEIK_BlueprintFunctions::GetProductUserID(UObject* Context)
{
	if(Context)
	{
		if(!Context->GetWorld())
		{
			return FString();
		}
		if(const IOnlineSubsystem *SubsystemRef = IOnlineSubsystem::Get())
		{
			if(const IOnlineIdentityPtr IdentityPointerRef = SubsystemRef->GetIdentityInterface())
			{
				if(const TSharedPtr<const FUniqueNetId> EIK_NetID = UGameplayStatics::GetGameInstance(Context->GetWorld())->GetFirstGamePlayer()->GetPreferredUniqueNetId().GetUniqueNetId())
				{
					const FString String_UserID = EIK_NetID.Get()->ToString();
					TArray<FString> Substrings;
					String_UserID.ParseIntoArray(Substrings, TEXT("|"));
					// Check if the split was successful
					// Check if the split was successful
					if (Substrings.Num() == 2)
					{
						return Substrings[1];
					}
					else if(Substrings.Num() == 1)
					{
						return Substrings[0];
					}
					else
					{
						return FString();
					}
				}
				else
				{
					return FString();
				}
			}
			else
			{
				return FString();
			}
		}
		else
		{
			return FString();
		}
	}
	else
	{
		return FString();
	}
}

bool UEIK_BlueprintFunctions::ShowFriendsList()
{
	const IOnlineSubsystem* OnlineSubsystem = IOnlineSubsystem::Get(); // Get the Online Subsystem
	if (OnlineSubsystem != nullptr)
	{
		const IOnlineExternalUIPtr ExternalUI = OnlineSubsystem->GetExternalUIInterface();        
		if (ExternalUI.IsValid())
		{
			return ExternalUI->ShowFriendsUI(0);
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool UEIK_BlueprintFunctions::StartSession(FName SessionName)
{
	if(const IOnlineSubsystem *SubsystemRef = IOnlineSubsystem::Get())
	{
		if(const IOnlineSessionPtr SessionPtrRef = SubsystemRef->GetSessionInterface())
		{
			return SessionPtrRef->StartSession(SessionName);
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool UEIK_BlueprintFunctions::RegisterPlayer(FName SessionName, FEIKUniqueNetId PlayerId, bool bWasInvited)
{
	if(const IOnlineSubsystem *SubsystemRef = IOnlineSubsystem::Get())
	{
		if(const IOnlineSessionPtr SessionPtrRef = SubsystemRef->GetSessionInterface())
		{
			if(const IOnlineIdentityPtr IdentityPointerRef = SubsystemRef->GetIdentityInterface())
			{
				return SessionPtrRef->RegisterPlayer(SessionName, PlayerId.UniqueNetId.ToSharedRef().Get(),bWasInvited);
			}
		}
	}
	return false;
}

bool UEIK_BlueprintFunctions::UnRegisterPlayer(FName SessionName, FEIKUniqueNetId PlayerId)
{
	if(const IOnlineSubsystem *SubsystemRef = IOnlineSubsystem::Get())
	{
		if(const IOnlineSessionPtr SessionPtrRef = SubsystemRef->GetSessionInterface())
		{
			if(const IOnlineIdentityPtr IdentityPointerRef = SubsystemRef->GetIdentityInterface())
			{
				return SessionPtrRef->UnregisterPlayer(SessionName, PlayerId.UniqueNetId.ToSharedRef().Get());
			}
		}
	}
	return false;
}

bool UEIK_BlueprintFunctions::EndSession(FName SessionName)
{
	if(const IOnlineSubsystem *SubsystemRef = IOnlineSubsystem::Get())
	{
		if(const IOnlineSessionPtr SessionPtrRef = SubsystemRef->GetSessionInterface())
		{
			return SessionPtrRef->EndSession(SessionName);
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

FString UEIK_BlueprintFunctions::GetPlayerNickname(const int32 LocalUserNum)
{
	FString Nickname;
	if(const IOnlineSubsystem *SubsystemRef = IOnlineSubsystem::Get())
	{
		if(const IOnlineIdentityPtr IdentityPointerRef = SubsystemRef->GetIdentityInterface())
		{
			Nickname =  IdentityPointerRef->GetPlayerNickname(LocalUserNum);
		}
	}
	if(Nickname.IsEmpty())
	{
		if(const IOnlineSubsystem *SubsystemRef = IOnlineSubsystem::GetByPlatform(false))
		{
			if(const IOnlineIdentityPtr IdentityPointerRef = SubsystemRef->GetIdentityInterface())
			{
				Nickname =  IdentityPointerRef->GetPlayerNickname(LocalUserNum);
			}
		}
	}
	return Nickname;
}

EEIK_LoginStatus UEIK_BlueprintFunctions::GetLoginStatus(const int32 LocalUserNum)
{
	if(const IOnlineSubsystem *SubsystemRef = IOnlineSubsystem::Get())
	{
		if(const IOnlineIdentityPtr IdentityPointerRef = SubsystemRef->GetIdentityInterface())
		{
			switch (IdentityPointerRef->GetLoginStatus(LocalUserNum))
			{
			case ELoginStatus::NotLoggedIn:
				return EEIK_LoginStatus::NotLoggedIn;
				break;
			case ELoginStatus::UsingLocalProfile:
				return EEIK_LoginStatus::UsingLocalProfile;
				break;
			case ELoginStatus::LoggedIn:
				return EEIK_LoginStatus::LoggedIn;
				break;
			default:
				return EEIK_LoginStatus::NotLoggedIn;
			}
		}
		return EEIK_LoginStatus::NotLoggedIn;
	}
	return EEIK_LoginStatus::NotLoggedIn;
}

FString UEIK_BlueprintFunctions::GenerateSessionCode(int32 CodeLength)
{
	FString SessionCode;

	for (int32 i = 0; i < CodeLength; i++)
	{
		const int32 RandomNumber = FMath::RandRange(0, 35);

		// Convert the random number into a character (0-9, A-Z)
		TCHAR RandomChar = (RandomNumber < 10) ? TCHAR('0' + RandomNumber) : TCHAR('A' + (RandomNumber - 10));

		// Append the character to the session code
		SessionCode.AppendChar(RandomChar);
	}

	return SessionCode;
}

bool UEIK_BlueprintFunctions::IsEIKActive()
{
	if (const IOnlineSubsystem* OnlineSubsystem = IOnlineSubsystem::Get())
	{
		const FName ActiveSubsystemName = OnlineSubsystem->GetSubsystemName();
		if(ActiveSubsystemName=="EIK")
		{
			return true;
		}
	}
	return false;
}

FName UEIK_BlueprintFunctions::GetActiveSubsystem()
{
	if (const IOnlineSubsystem* OnlineSubsystem = IOnlineSubsystem::Get())
	{
		return  OnlineSubsystem->GetSubsystemName();
	}
	return FName();
}

ELoginTypes UEIK_BlueprintFunctions::GetActivePlatformSubsystem()
{
	if(const IOnlineSubsystem *SubsystemRef = IOnlineSubsystem::GetByPlatform(false))
	{
		if(SubsystemRef->GetSubsystemName() == TEXT("STEAM"))
		{
			return ELoginTypes::Steam;
		}
		else if(SubsystemRef->GetSubsystemName() == TEXT("GOOGLEPLAY"))
		{
			return ELoginTypes::Google;
		}
	}
	return ELoginTypes::None;
}

FString UEIK_BlueprintFunctions::ByteArrayToString(const TArray<uint8>& DataToConvert)
{
	FString Result = FBase64::Encode(DataToConvert.GetData(), DataToConvert.Num());
	return Result;
}

TArray<uint8> UEIK_BlueprintFunctions::StringToByteArray(const FString& DataToConvert)
{
	TArray<uint8> Result;
	FBase64::Decode(DataToConvert, Result);
	return Result;
}

FEIKUniqueNetId UEIK_BlueprintFunctions::GetUserUniqueID(const APlayerController* PlayerController)
{
	if(const TSharedPtr<const FUniqueNetId> EIK_NetID = UGameplayStatics::GetGameInstance(PlayerController->GetWorld())->GetFirstGamePlayer()->GetPreferredUniqueNetId().GetUniqueNetId())
	{
		FEIKUniqueNetId LocalUNetID;
		LocalUNetID.SetUniqueNetId(EIK_NetID);
		if(LocalUNetID.IsValid())
		{
			return LocalUNetID;
		}
		return FEIKUniqueNetId();
	}
	return FEIKUniqueNetId();
}

bool UEIK_BlueprintFunctions::IsValidSession(FSessionFindStruct Session)
{
	if(Session.bIsDedicatedServer)
	{
		return true;
	}
	if(Session.SessionResult.OnlineResult.Session.NumOpenPublicConnections > 0 || Session.SessionResult.OnlineResult.Session.NumOpenPrivateConnections > 0)
	{
		return true;
	}
	return false;
}

bool UEIK_BlueprintFunctions::Initialize_EIK_For_Friends(APlayerController* PlayerController)
{
	if (UEIK_Subsystem* EIK_Subsystem = PlayerController->GetGameInstance()->GetSubsystem<UEIK_Subsystem>())
	{
		return EIK_Subsystem->InitializeEIK();
	}
	return false;
}

FString UEIK_BlueprintFunctions::GetCurrentPort(AGameModeBase* CurrentGameMode)
{
	if(!CurrentGameMode)
	{
		return FString();
	}
	return FString::FromInt(CurrentGameMode->GetWorld()->URL.Port);
}
