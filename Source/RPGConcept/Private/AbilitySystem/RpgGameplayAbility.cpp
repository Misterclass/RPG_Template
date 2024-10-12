// Paul Polbitsev (@evilowl). All Rights Reserved


#include "AbilitySystem/RpgGameplayAbility.h"
#include "AbilitySystemComponent.h"


void URpgGameplayAbility::OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnGiveAbility(ActorInfo, Spec);

	if (ActivationPolicy == OnGiven)
	{
		UAbilitySystemComponent* ASC = ActorInfo->AbilitySystemComponent.Get();
		ASC->TryActivateAbility(Spec.Handle);
	}
}

void URpgGameplayAbility::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);

	if (ActivationPolicy == OnGiven)
	{
		UAbilitySystemComponent* ASC = ActorInfo->AbilitySystemComponent.Get();
		ASC->ClearAbility(Handle);
	}
}
