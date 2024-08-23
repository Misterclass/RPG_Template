// Paul Polbitsev (@evilowl). All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "GameplayTagContainer.h"
#include "Input/DAInputConfig.h"
#include "InputAction.h"
#include "RpgEnhancedInputComponent.generated.h"

class UDAInputConfig;

/**
 * 
 */
UCLASS()
class RPGCONCEPT_API URpgEnhancedInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()
	
public:

	template<class UserObject, typename CallbackFunc>
	void BindNativeInputAction(const UDAInputConfig* InInputConfig, const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Func);
};

template<class UserObject, typename CallbackFunc>
inline void URpgEnhancedInputComponent::BindNativeInputAction(const UDAInputConfig* InInputConfig, const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Func)
{
	checkf(InInputConfig, TEXT("You're binding to incorrect input config!"));
	UInputAction* Action = InInputConfig->FindActionByTag(InInputTag);
	checkf(Action, TEXT("No matched action in your Input Config!!"));
	BindAction(Action, TriggerEvent, ContextObject, Func);
}
