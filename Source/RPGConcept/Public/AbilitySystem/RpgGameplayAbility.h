// Paul Polbitsev (@evilowl). All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "RpgGameplayAbility.generated.h"

UENUM(BlueprintType)
enum ERpgGameplayAbilityActivationPolicy : uint8
{
	OnGiven,
	OnTriggered
};

/**
 * 
 */
UCLASS()
class RPGCONCEPT_API URpgGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec);
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled);
	
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Rpg")
	TEnumAsByte<ERpgGameplayAbilityActivationPolicy> ActivationPolicy;
};
