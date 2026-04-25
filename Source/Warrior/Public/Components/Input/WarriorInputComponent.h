// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "WarriorInputComponent.generated.h"

struct FGameplayTag;
class UDataAsset_InputConfig;
/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()
	
public:
	template<class UserObject, typename CallbackFunction>
	void BindNativeInputAction(const UDataAsset_InputConfig* InputConfig, const FGameplayTag& Tag, 
		ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunction Function);
	
};

template <class UserObject, typename CallbackFunction>
void UWarriorInputComponent::BindNativeInputAction(const UDataAsset_InputConfig* InputConfig, const FGameplayTag& Tag,
	ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunction Function)
{
	checkf(InputConfig, TEXT("Input Config Data Asset is null"));

	if (UInputAction* FoundAction = InputConfig->FindNativeInputActionByTag(Tag))
	{
		BindAction(FoundAction, TriggerEvent, ContextObject, Function);
	}
}
