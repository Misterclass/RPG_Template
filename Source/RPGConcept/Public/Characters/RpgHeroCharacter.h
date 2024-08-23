// Paul Polbitsev (@evilowl). All Rights Reserved

#pragma once

#include "RPG.h"
#include "Characters/RpgBaseCharacter.h"
#include "RpgHeroCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UDAInputConfig;
struct FInputActionValue;

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
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

private:
#pragma region Components

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;

#pragma endregion 

#pragma region Input

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Config", meta = (AllowPrivateAccess = "true"))
	UDAInputConfig* InputConfig;

#pragma endregion 

};
