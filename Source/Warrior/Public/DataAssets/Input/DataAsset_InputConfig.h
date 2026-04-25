// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "DataAsset_InputConfig.generated.h"

class UInputMappingContext;
class UInputAction;

/**
 * 
 */
UCLASS()
class WARRIOR_API UDataAsset_InputConfig : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UInputMappingContext> DefaultMappingContext;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(TitleProperty = "InputTag"))
	TMap<FGameplayTag, UInputAction*> NativeInputActions;
	
	UInputAction* FindNativeInputActionByTag(const FGameplayTag& Tag) const;
};
