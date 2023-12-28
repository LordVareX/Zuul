/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/StreamSpecification.h"

#endif

#include "DynamoDBStreamViewType.h"

#include "StreamSpecification.generated.h"

USTRUCT(BlueprintType)
struct FStreamSpecification {
GENERATED_BODY()

    /**
    *  <p>Indicates whether DynamoDB Streams is enabled (true) or disabled (false) on the table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    bool streamEnabled = false;

    /**
    *  <p> When an item in the table is modified, <code>StreamViewType</code> determines what information is written to the stream for this table. Valid values for <code>StreamViewType</code> are:</p> <ul> <li> <p> <code>KEYS_ONLY</code> - Only the key attributes of the modified item are written to the stream.</p> </li> <li> <p> <code>NEW_IMAGE</code> - The entire item, as it appears after it was modified, is written to the stream.</p> </li> <li> <p> <code>OLD_IMAGE</code> - The entire item, as it appeared before it was modified, is written to the stream.</p> </li> <li> <p> <code>NEW_AND_OLD_IMAGES</code> - Both the new and the old item images of the item are written to the stream.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSDynamoDBStreamViewType streamViewType = EAWSDynamoDBStreamViewType::NOT_SET;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::StreamSpecification toAWS() const {
        Aws::DynamoDB::Model::StreamSpecification awsStreamSpecification;

        awsStreamSpecification.SetStreamEnabled(this->streamEnabled);

        switch(this->streamViewType) {
            case EAWSDynamoDBStreamViewType::NEW_IMAGE:
                awsStreamSpecification.SetStreamViewType(Aws::DynamoDB::Model::StreamViewType::NEW_IMAGE);
                break;
            case EAWSDynamoDBStreamViewType::OLD_IMAGE:
                awsStreamSpecification.SetStreamViewType(Aws::DynamoDB::Model::StreamViewType::OLD_IMAGE);
                break;
            case EAWSDynamoDBStreamViewType::NEW_AND_OLD_IMAGES:
                awsStreamSpecification.SetStreamViewType(Aws::DynamoDB::Model::StreamViewType::NEW_AND_OLD_IMAGES);
                break;
            case EAWSDynamoDBStreamViewType::KEYS_ONLY:
                awsStreamSpecification.SetStreamViewType(Aws::DynamoDB::Model::StreamViewType::KEYS_ONLY);
                break;
            default:
                break;
            }

        return awsStreamSpecification;
    }

    bool IsEmpty() const {
        return false && this->streamViewType == EAWSDynamoDBStreamViewType::NOT_SET;
    }

    FStreamSpecification &fromAWS(const Aws::DynamoDB::Model::StreamSpecification &awsStreamSpecification) {
        this->streamEnabled = awsStreamSpecification.GetStreamEnabled();

        switch(awsStreamSpecification.GetStreamViewType()) {
            case Aws::DynamoDB::Model::StreamViewType::NOT_SET:
                this->streamViewType = EAWSDynamoDBStreamViewType::NOT_SET;
                break;
            case Aws::DynamoDB::Model::StreamViewType::NEW_IMAGE:
                this->streamViewType = EAWSDynamoDBStreamViewType::NEW_IMAGE;
                break;
            case Aws::DynamoDB::Model::StreamViewType::OLD_IMAGE:
                this->streamViewType = EAWSDynamoDBStreamViewType::OLD_IMAGE;
                break;
            case Aws::DynamoDB::Model::StreamViewType::NEW_AND_OLD_IMAGES:
                this->streamViewType = EAWSDynamoDBStreamViewType::NEW_AND_OLD_IMAGES;
                break;
            case Aws::DynamoDB::Model::StreamViewType::KEYS_ONLY:
                this->streamViewType = EAWSDynamoDBStreamViewType::KEYS_ONLY;
                break;
            default:
                this->streamViewType = EAWSDynamoDBStreamViewType::NOT_SET;
                break;
            }

        return *this;
    }
#endif
};
