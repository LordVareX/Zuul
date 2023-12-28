/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/ListUsersRequest.h"

#endif

#include "ListUsersRequest.generated.h"

USTRUCT(BlueprintType)
struct FListUsersRequest {
GENERATED_BODY()

    /**
    *  <p>The user pool ID for the user pool on which the search should be performed.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>An array of strings, where each string is the name of a user attribute to be returned for each user in the search results. If the array is null, all attributes are returned.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FString> attributesToGet;

    /**
    *  <p>Maximum number of users to be returned.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    int limit = 0;

    /**
    *  <p>An identifier that was returned from the previous call to this operation, which can be used to return the next set of items in the list.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString paginationToken;

    /**
    *  <p>A filter string of the form "<i>AttributeName</i> <i>Filter-Type</i> "<i>AttributeValue</i>"". Quotation marks within the filter string must be escaped using the backslash (\) character. For example, "<code>family_name</code> = \"Reddy\"".</p> <ul> <li> <p> <i>AttributeName</i>: The name of the attribute to search for. You can only search for one attribute at a time.</p> </li> <li> <p> <i>Filter-Type</i>: For an exact match, use =, for example, "<code>given_name</code> = \"Jon\"". For a prefix ("starts with") match, use ^=, for example, "<code>given_name</code> ^= \"Jon\"". </p> </li> <li> <p> <i>AttributeValue</i>: The attribute value that must be matched for each user.</p> </li> </ul> <p>If the filter string is empty, <code>ListUsers</code> returns all users in the user pool.</p> <p>You can only search for the following standard attributes:</p> <ul> <li> <p> <code>username</code> (case-sensitive)</p> </li> <li> <p> <code>email</code> </p> </li> <li> <p> <code>phone_number</code> </p> </li> <li> <p> <code>name</code> </p> </li> <li> <p> <code>given_name</code> </p> </li> <li> <p> <code>family_name</code> </p> </li> <li> <p> <code>preferred_username</code> </p> </li> <li> <p> <code>cognito:user_status</code> (called <b>Status</b> in the Console) (case-insensitive)</p> </li> <li> <p> <code>status (called <b>Enabled</b> in the Console) (case-sensitive)</code> </p> </li> <li> <p> <code>sub</code> </p> </li> </ul> <p>Custom attributes are not searchable.</p> <p>For more information, see <a href="http://docs.aws.amazon.com/cognito/latest/developerguide/how-to-manage-user-accounts.html#cognito-user-pools-searching-for-users-using-listusers-api">Searching for Users Using the ListUsers API</a> and <a href="http://docs.aws.amazon.com/cognito/latest/developerguide/how-to-manage-user-accounts.html#cognito-user-pools-searching-for-users-listusers-api-examples">Examples of Using the ListUsers API</a> in the <i>Amazon Cognito Developer Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString filter;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::ListUsersRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::ListUsersRequest awsListUsersRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsListUsersRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        for (const FString& elem : this->attributesToGet) {
            awsListUsersRequest.AddAttributesToGet(TCHAR_TO_UTF8(*elem));
        }

        if (this->limit != 0) {
            awsListUsersRequest.SetLimit(this->limit);
        }

        if (!(this->paginationToken.IsEmpty())) {
            awsListUsersRequest.SetPaginationToken(TCHAR_TO_UTF8(*this->paginationToken));
        }

        if (!(this->filter.IsEmpty())) {
            awsListUsersRequest.SetFilter(TCHAR_TO_UTF8(*this->filter));
        }

        return awsListUsersRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty() && this->attributesToGet.Num() == 0 && this->limit == 0 && this->paginationToken.IsEmpty() && this->filter.IsEmpty();
    }
#endif
};
