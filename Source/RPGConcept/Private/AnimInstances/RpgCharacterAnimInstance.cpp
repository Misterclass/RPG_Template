// Paul Polbitsev (@evilowl). All Rights Reserved


#include "AnimInstances/RpgCharacterAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Characters/RpgBaseCharacter.h"

void URpgCharacterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	OwningCharacter = Cast<ARpgBaseCharacter>(TryGetPawnOwner());
	//Lol. It gets called even in editor. 
	//You must protect these moments by if
	if (OwningCharacter)
	{
		OwningCharacterMovement = OwningCharacter->GetCharacterMovement();
	}
}

void URpgCharacterAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);

	if (!OwningCharacter || !OwningCharacterMovement)
	{
		return;
	}

	//Velocity length = speed
	//Lifehack = use Size() instead of Length() One call economy :)
	GroundSpeed = OwningCharacterMovement->Velocity.Size();

	//Acceleration = Input Vector * Max Acceleration. It's speed in one tick.
	/*
	* Size squared2D because:
	* 1.We don't need Z axis
	* 2. We don't need Sqrt operation (like on usual Size()). We just need to know bool value (> 0 or not)
	*/
	bHasAcceleration = OwningCharacterMovement->GetCurrentAcceleration().SizeSquared2D() > 0.f;
}
