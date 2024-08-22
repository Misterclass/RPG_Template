// Paul Polbitsev (@evilowl). All Rights Reserved


#include "Controllers/RpgHeroController.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"


void ARpgHeroController::BeginPlay()
{
	Super::BeginPlay();

	ULocalPlayer* LocalPlayer = CastChecked<ULocalPlayer>(Player);
	UEnhancedInputLocalPlayerSubsystem* InputSystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	check(InputMapping);
	check(InputSystem);
	InputSystem->AddMappingContext(InputMapping, 1);
}
