// Paul Polbitsev (@evilowl). All Rights Reserved


#include "AnimInstances/RpgPlayerAnimInstance.h"
#include "Characters/RpgHeroCharacter.h"


void URpgPlayerAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	if (OwningCharacter)
	{
		HeroCharacter = Cast<ARpgHeroCharacter>(OwningCharacter);
	}
}

void URpgPlayerAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);

	if (HeroCharacter)
	{
		IdleStateTime = (!bHasAcceleration) ? IdleStateTime + DeltaSeconds : 0.f;
		bShouldEnterRelaxState = IdleStateTime > EnterRelaxStateTime;
	}
}
