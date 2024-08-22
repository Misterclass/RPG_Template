// Paul Polbitsev (@evilowl). All Rights Reserved


#include "Characters/RpgHeroCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "InputAction.h"
#include "EnhancedInputComponent.h"
#include "Kismet/KismetMathLibrary.h"


ARpgHeroCharacter::ARpgHeroCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);

	//No rotation by controller input. We must control only camera
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera Boom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 200.f;
	CameraBoom->SocketOffset = FVector(0.f, 55.f, 60.f);
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Follow Camera"));
	FollowCamera->SetupAttachment(CameraBoom);
	FollowCamera->bUsePawnControlRotation = false;

	UCharacterMovementComponent* CharacterMovementComp = GetCharacterMovement();
	CharacterMovementComp->MaxWalkSpeed = 200.f;
	CharacterMovementComp->RotationRate = FRotator(0.f, 500.f, 0.f);
	CharacterMovementComp->bOrientRotationToMovement = true;
}

void ARpgHeroCharacter::BeginPlay()
{
	Super::BeginPlay();
	Debug::Print(TEXT("Hello World!"));
}

void ARpgHeroCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EnhancedInputComp = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);
	EnhancedInputComp->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ThisClass::Move);
	EnhancedInputComp->BindAction(LookAction, ETriggerEvent::Triggered, this, &ThisClass::Look);
}

void ARpgHeroCharacter::Move(const FInputActionValue& Value)
{
	FVector2D Value2D = Value.Get<FVector2D>();
	FRotator ControlRotation = GetControlRotation();

	FVector ForwardVector = UKismetMathLibrary::GetForwardVector(FRotator(0.f, ControlRotation.Yaw, ControlRotation.Roll));
	FVector RightVector = UKismetMathLibrary::GetRightVector(FRotator(0.f, ControlRotation.Yaw, 0.f));

	AddMovementInput(ForwardVector, Value2D.Y);
	AddMovementInput(RightVector, Value2D.X);
}

void ARpgHeroCharacter::Look(const FInputActionValue& Value)
{
	FVector2D Value2D = Value.Get<FVector2D>();
	AddControllerYawInput(Value2D.X);
	AddControllerPitchInput(Value2D.Y);
}
