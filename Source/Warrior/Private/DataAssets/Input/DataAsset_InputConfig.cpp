// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/Input/DataAsset_InputConfig.h"

UInputAction* UDataAsset_InputConfig::FindNativeInputActionByTag(const FGameplayTag& Tag)
{
	for (const FWarriorInputActionConfig& InputAction : NativeInputActions)
	{
		if (InputAction.InputTag == Tag && InputAction.InputAction)
		{
			return InputAction.InputAction;
		}
	}
	
	return nullptr;
}
