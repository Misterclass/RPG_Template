// Paul Polbitsev (@evilowl). All Rights Reserved


#include "Characters/RpgBaseCharacter.h"
#include "AbilitySystem/RpgBaseAttributeSet.h"
#include "AbilitySystem/RpgAbilitySystemComponent.h"


// Sets default values
ARpgBaseCharacter::ARpgBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetMesh()->bReceivesDecals = false;

	AbilitySystemComponent = CreateDefaultSubobject<URpgAbilitySystemComponent>(TEXT("Abilisty System Component"));
	AttributeSet = CreateDefaultSubobject<URpgBaseAttributeSet>(TEXT("Attribute set"));
}

void ARpgBaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->InitAbilityActorInfo(this, this);
	}
}

UAbilitySystemComponent* ARpgBaseCharacter::GetAbilitySystemComponent() const
{
	return GetRpgAbilitySystemComponent();
}
