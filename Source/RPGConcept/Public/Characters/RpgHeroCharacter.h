// Paul Polbitsev (@evilowl). All Rights Reserved

#pragma once

#include "RPG.h"
#include "Characters/RpgBaseCharacter.h"
#include "RpgHeroCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

/**
 * 
 */
UCLASS()
class RPGCONCEPT_API ARpgHeroCharacter : public ARpgBaseCharacter
{
	GENERATED_BODY()
	
public:
	ARpgHeroCharacter();

protected:
	virtual void BeginPlay() override;

private:
#pragma region Components

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;
#pragma endregion 

};
