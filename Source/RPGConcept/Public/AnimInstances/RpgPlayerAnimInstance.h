// Paul Polbitsev (@evilowl). All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/RpgCharacterAnimInstance.h"
#include "RpgPlayerAnimInstance.generated.h"

class ARpgHeroCharacter;

/**
 * 
 */
UCLASS()
class RPGCONCEPT_API URpgPlayerAnimInstance : public URpgCharacterAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Character", meta = (AllowPrivateAcces = true))
	ARpgHeroCharacter* HeroCharacter = nullptr;
	
	//Every state on state machine must have their transition condition!
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Data", meta = (AllowPrivateAcces = true))
	bool bShouldEnterRelaxState = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Data", meta = (AllowPrivateAcces = true))
	float EnterRelaxStateTime = 5.f;

private:
	float IdleStateTime = 0.f;
};
