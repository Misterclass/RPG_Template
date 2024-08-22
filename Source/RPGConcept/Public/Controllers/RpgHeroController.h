// Paul Polbitsev (@evilowl). All Rights Reserved

#pragma once

#include "RPG.h"
#include "GameFramework/PlayerController.h"
#include "RpgHeroController.generated.h"

class UInputMappingContext;

/**
 * 
 */
UCLASS()
class RPGCONCEPT_API ARpgHeroController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* InputMapping;
};
