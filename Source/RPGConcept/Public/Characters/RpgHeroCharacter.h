// Paul Polbitsev (@evilowl). All Rights Reserved

#pragma once

#include "RPG.h"
#include "Characters/RpgBaseCharacter.h"
#include "RpgHeroCharacter.generated.h"

/**
 * 
 */
UCLASS()
class RPGCONCEPT_API ARpgHeroCharacter : public ARpgBaseCharacter
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;
};
