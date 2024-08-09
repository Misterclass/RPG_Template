// Paul Polbitsev (@evilowl). All Rights Reserved


#include "Characters/RpgBaseCharacter.h"

// Sets default values
ARpgBaseCharacter::ARpgBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetMesh()->bReceivesDecals = false;
}
