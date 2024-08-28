// Paul Polbitsev (@evilowl). All Rights Reserved

#pragma once

#include "RPG.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "RpgBaseCharacter.generated.h"

class URpgAbilitySystemComponent;
class URpgBaseAttributeSet;

UCLASS()
class RPGCONCEPT_API ARpgBaseCharacter : public ACharacter, 
										 public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ARpgBaseCharacter();

	//~ Begin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface

	//~ Begin IAbilitySystem Interface
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	//~ End IAbilitySystem Interface


	FORCEINLINE URpgAbilitySystemComponent* GetRpgAbilitySystemComponent() const { return AbilitySystemComponent;  }
	FORCEINLINE URpgBaseAttributeSet* GetRpgAttributeSet() const { return AttributeSet; }

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ability System")
	URpgAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ability System")
	URpgBaseAttributeSet* AttributeSet;

};
