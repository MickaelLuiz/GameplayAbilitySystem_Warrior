// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/Input/DataAsset_InputConfig.h"

UInputAction* UDataAsset_InputConfig::FindNativeInputActionByTag(const FGameplayTag& Tag) const
{
	if (NativeInputActions.Contains(Tag))
	{
		return NativeInputActions[Tag];
	}
	
	return nullptr;
}
