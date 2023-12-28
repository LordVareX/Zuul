/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Written by Siqi.Wu <lion547016@gmail.com>, Oct 2021
 */

#include "DynamoDBAttributeValueHelper.h"

#include "DynamoDBGlobals.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/core/external/cjson/cJSON.h"

#include <vector>
#include <cstdlib>
#include <string>
#include <cstring>

#endif

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

static unsigned char* strdup(const unsigned char* string)
{
    size_t length = 0;
    unsigned char *copy = NULL;

    if (string == NULL)
    {
        return NULL;
    }

    length = std::strlen((const char*)string) + sizeof("");
    copy = (unsigned char *)cJSON_AS4CPP_malloc(length);
    if (copy == NULL)
    {
        return NULL;
    }
    std::memcpy(copy, string, length);

    return copy;
}

cJSON *JsonToDynamoDBAttributeValueNode(cJSON *json);

std::vector<cJSON *> JsonToDynamoDBAttributeValueContainer(cJSON *json) {
    cJSON *current_element = json->child;

    std::vector<cJSON *> container;
    while (current_element != nullptr) {
        container.push_back(JsonToDynamoDBAttributeValueNode(current_element));

        current_element = current_element->next;
    }

    return container;
}

cJSON *JsonToDynamoDBAttributeValueNode(cJSON *json) {
    cJSON *attributeValueNode = cJSON_AS4CPP_CreateObject();

    if (json->string) {
        attributeValueNode->string = (char *)strdup((const unsigned char*)(json->string));
    }

    if (json != nullptr) {
        switch (json->type & 0xFF) {
            case cJSON_AS4CPP_Invalid:
            case cJSON_AS4CPP_NULL: {
                cJSON_AS4CPP_AddTrueToObject(attributeValueNode, "NULL");
                break;
            }
            case cJSON_AS4CPP_False: {
                cJSON_AS4CPP_AddFalseToObject(attributeValueNode, "BOOL");
                break;
            }
            case cJSON_AS4CPP_True: {
                cJSON_AS4CPP_AddTrueToObject(attributeValueNode, "BOOL");
                break;
            }
            case cJSON_AS4CPP_Number: {
                cJSON_AS4CPP_AddStringToObject(attributeValueNode, "N", std::to_string(json->valuedouble).c_str());
                break;
            }
            case cJSON_AS4CPP_String:
            case cJSON_AS4CPP_Raw: {
                cJSON_AS4CPP_AddStringToObject(attributeValueNode, "S", json->valuestring);
                break;
            }
            case cJSON_AS4CPP_Array: {
                cJSON *array = cJSON_AS4CPP_AddArrayToObject(attributeValueNode, "L");
                std::vector<cJSON *> container = JsonToDynamoDBAttributeValueContainer(json);

                for (cJSON *container_node : container) {
                    cJSON_AS4CPP_AddItemToArray(array, container_node);
                }

                break;
            }
            case cJSON_AS4CPP_Object: {
                cJSON *map = cJSON_AS4CPP_AddObjectToObject(attributeValueNode, "M");
                std::vector<cJSON *> container = JsonToDynamoDBAttributeValueContainer(json);

                for (cJSON *container_node : container) {
                    cJSON_AS4CPP_AddItemToObject(map, container_node->string, container_node);
                }

                break;
            }
        }
    }

    return attributeValueNode;
}

#endif

FString UDynamoDBAttributeValueHelper::JsonToDynamoDBAttributeValue(FString json) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    const char* return_parse_end;
    cJSON *cjson = cJSON_AS4CPP_ParseWithOpts(TCHAR_TO_UTF8(*json), &return_parse_end, 1);

    if (!cjson || cJSON_AS4CPP_IsInvalid(cjson)) {
        LOG_DYNAMODB_WARNING(FString::Printf(TEXT("Error before: %s"), UTF8_TO_TCHAR(return_parse_end)));
        cJSON_AS4CPP_Delete(cjson);
        return FString();
    }

    cJSON *cjsonAttributeValue = JsonToDynamoDBAttributeValueNode(cjson);

    char *string = cJSON_AS4CPP_Print(cjsonAttributeValue);
    if (string == nullptr)
    {
        LOG_DYNAMODB_WARNING("Failed to print");
    }

    cJSON_AS4CPP_Delete(cjson);
    cJSON_AS4CPP_Delete(cjsonAttributeValue);

    return UTF8_TO_TCHAR(string);
#else
    return FString();
#endif
}

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

std::vector<cJSON *> DynamoDBAttributeValueToJsonContainer(cJSON *attributeValue);

cJSON *DynamoDBAttributeValueToJsonNode(cJSON *attributeValue) {
    if (attributeValue == nullptr) {
        return nullptr;
    }

    if ((attributeValue->type & 0xFF) != cJSON_AS4CPP_Object) {
        return nullptr;
    }

    cJSON *current_element = attributeValue->child;

    cJSON *node = nullptr;
    while (current_element != nullptr) {
        if (strcmp(current_element->string, "S") == 0) {
            if ((current_element->type & 0xFF) != cJSON_AS4CPP_String) {
                return nullptr;
            }
            node = cJSON_AS4CPP_CreateString(current_element->valuestring);
        } else if (strcmp(current_element->string, "N") == 0) {
            if ((current_element->type & 0xFF) != cJSON_AS4CPP_String) {
                return nullptr;
            }
            node = cJSON_AS4CPP_CreateNumber(std::atof(current_element->valuestring));
        } else if (strcmp(current_element->string, "B") == 0) {
            if ((current_element->type & 0xFF) != cJSON_AS4CPP_String) {
                return nullptr;
            }
            node = cJSON_AS4CPP_CreateString(current_element->valuestring);
        } else if (strcmp(current_element->string, "SS") == 0) {
            if ((current_element->type & 0xFF) != cJSON_AS4CPP_Array) {
                return nullptr;
            }
            node = cJSON_AS4CPP_CreateArray();

            cJSON *current_element_child = current_element->child;
            while (current_element_child != nullptr) {
                if ((current_element_child->type & 0xFF) == cJSON_AS4CPP_String) {
                    cJSON_AS4CPP_AddItemToArray(node, cJSON_AS4CPP_CreateString(current_element_child->valuestring));
                }

                current_element_child = current_element_child->next;
            }
        } else if (strcmp(current_element->string, "NS") == 0) {
            if ((current_element->type & 0xFF) != cJSON_AS4CPP_Array) {
                return nullptr;
            }
            node = cJSON_AS4CPP_CreateArray();

            cJSON *current_element_child = current_element->child;
            while (current_element_child != nullptr) {
                if ((current_element_child->type & 0xFF) == cJSON_AS4CPP_String) {
                    cJSON_AS4CPP_AddItemToArray(node, cJSON_AS4CPP_CreateNumber(std::atof(current_element_child->valuestring)));
                }

                current_element_child = current_element_child->next;
            }
        } else if (strcmp(current_element->string, "BS") == 0) {
            if ((current_element->type & 0xFF) != cJSON_AS4CPP_Array) {
                return nullptr;
            }
            node = cJSON_AS4CPP_CreateArray();

            cJSON *current_element_child = current_element->child;
            while (current_element_child != nullptr) {
                if ((current_element_child->type & 0xFF) == cJSON_AS4CPP_String) {
                    cJSON_AS4CPP_AddItemToArray(node, cJSON_AS4CPP_CreateString(current_element_child->valuestring));
                }

                current_element_child = current_element_child->next;
            }
        } else if (strcmp(current_element->string, "M") == 0) {
            if ((current_element->type & 0xFF) != cJSON_AS4CPP_Object) {
                return nullptr;
            }

            std::vector<cJSON *> container = DynamoDBAttributeValueToJsonContainer(current_element);
            node = cJSON_AS4CPP_CreateObject();

            for (cJSON *container_node : container) {
                cJSON_AS4CPP_AddItemToObject(node, container_node->string, container_node);
            }
        } else if (strcmp(current_element->string, "L") == 0) {
            if ((current_element->type & 0xFF) != cJSON_AS4CPP_Array) {
                return nullptr;
            }

            std::vector<cJSON *> container = DynamoDBAttributeValueToJsonContainer(current_element);
            node = cJSON_AS4CPP_CreateArray();

            for (cJSON *container_node : container) {
                cJSON_AS4CPP_AddItemToArray(node, container_node);
            }
        } else if (strcmp(current_element->string, "BOOL") == 0) {
            if ((current_element->type & 0xFF) != cJSON_AS4CPP_True && (current_element->type & 0xFF) != cJSON_AS4CPP_False) {
                return nullptr;
            }
            node = cJSON_AS4CPP_CreateBool((current_element->type & 0xFF) == cJSON_AS4CPP_True);
        } else if (strcmp(current_element->string, "NULL") == 0) {
            if ((current_element->type & 0xFF) != cJSON_AS4CPP_True && (current_element->type & 0xFF) != cJSON_AS4CPP_False) {
                return nullptr;
            }
            if ((current_element->type & 0xFF) == cJSON_AS4CPP_True) {
                node = cJSON_AS4CPP_CreateNull();
            }
        }
        
        current_element = current_element->next;
    }

    return node;
}

cJSON *DynamoDBItemToJson(cJSON *attributeValue) {
    cJSON *current_element = attributeValue->child;

    cJSON * item = cJSON_AS4CPP_CreateObject();
    while (current_element != nullptr) {
        cJSON *node = DynamoDBAttributeValueToJsonNode(current_element);

        if (node && current_element->string) {
            cJSON_AS4CPP_AddItemToObject(item, current_element->string, node);
        }

        current_element = current_element->next;
    }

    return item;
}

std::vector<cJSON *> DynamoDBAttributeValueToJsonContainer(cJSON *attributeValue) {
    cJSON *current_element = attributeValue->child;

    std::vector<cJSON *> container;
    while (current_element != nullptr) {
        cJSON *node = DynamoDBAttributeValueToJsonNode(current_element);

        if (node) {
            if (current_element->string) {
                node->string = (char *)strdup((const unsigned char *)current_element->string);
            }

            container.push_back(node);
        }

        current_element = current_element->next;
    }

    return container;
}

#endif

FString UDynamoDBAttributeValueHelper::DynamoDBAttributeValueToJson(FString attributeValue) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    const char* return_parse_end;
    cJSON *cjsonAttributeValue = cJSON_AS4CPP_ParseWithOpts(TCHAR_TO_UTF8(*attributeValue), &return_parse_end, 1);

    if (!cjsonAttributeValue || cJSON_AS4CPP_IsInvalid(cjsonAttributeValue)) {
        LOG_DYNAMODB_WARNING(FString::Printf(TEXT("Error before: %s"), UTF8_TO_TCHAR(return_parse_end)));
        cJSON_AS4CPP_Delete(cjsonAttributeValue);
        return FString();
    }

    cJSON *cjson = DynamoDBAttributeValueToJsonNode(cjsonAttributeValue);
    if (cjson == nullptr) {
        cjson = DynamoDBItemToJson(cjsonAttributeValue);

        if (cjson == nullptr) {
            LOG_DYNAMODB_WARNING("failed to convert");

            cJSON_AS4CPP_Delete(cjsonAttributeValue);

            return FString();
        }
    }

    char *string = cJSON_AS4CPP_Print(cjson);
    if (string == nullptr)
    {
        LOG_DYNAMODB_WARNING("Failed to print");
    }

    cJSON_AS4CPP_Delete(cjson);
    cJSON_AS4CPP_Delete(cjsonAttributeValue);

    return UTF8_TO_TCHAR(string);
#else
    return FString();
#endif
}
