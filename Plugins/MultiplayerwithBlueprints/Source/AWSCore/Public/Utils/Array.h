/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, May 2019
 */

#pragma once

#include "CoreMinimal.h"

#if WITH_CORE

#include "aws/core/utils/Array.h"
#include <iomanip>

#endif

#include "Array.generated.h"

USTRUCT(BlueprintType)
struct FAWSByteBuffer {
    GENERATED_BODY()

    /*
     * */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Client")
    TArray<uint8> buffer;

#if WITH_CORE
public:
    Aws::Utils::ByteBuffer toAWS() const {
        if (!(this->buffer.IsEmpty())) {
            Aws::Vector<unsigned char> bytes;
            
            for (int i = 0; i < this->buffer.Num(); i++) {
                bytes.push_back(this->buffer[i]);
            }
            
            Aws::Utils::ByteBuffer awsByteBuffer(bytes.data(), bytes.size());

            return awsByteBuffer;
            
        } else {
            return Aws::Utils::ByteBuffer();
        }
    };
    
    bool IsEmpty() const {
        return this->buffer.IsEmpty();
    }
    
    FAWSByteBuffer& fromAWS(const Aws::Utils::ByteBuffer& awsByteBuffer) {
        this->buffer.Empty();
        for (int i = 0; i < awsByteBuffer.GetLength(); i++) {
            this->buffer.Add((unsigned char)awsByteBuffer[i]);
        }

        return *this;
    };
#endif
};
