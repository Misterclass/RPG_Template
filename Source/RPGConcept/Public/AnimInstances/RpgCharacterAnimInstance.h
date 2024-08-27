// Paul Polbitsev (@evilowl). All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/RpgBaseAnimInstance.h"
#include "RpgCharacterAnimInstance.generated.h"

class ARpgBaseCharacter;
class UCharacterMovementComponent;

/**
 * 
 */
UCLASS()
class RPGCONCEPT_API URpgCharacterAnimInstance : public URpgBaseAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;
	
protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Character", meta=(AllowPrivateAcces = true))
	ARpgBaseCharacter* OwningCharacter = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Character", meta = (AllowPrivateAcces = true))
	UCharacterMovementComponent* OwningCharacterMovement = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Data", meta = (AllowPrivateAcces = true))
	float GroundSpeed = 0.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Data", meta = (AllowPrivateAcces = true))
	bool bHasAcceleration = false;
};
