// Paul Polbitsev (@evilowl). All Rights Reserved


#include "Items/Weapon/RPGWeaponBase.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"


ARPGWeaponBase::ARPGWeaponBase()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(GetRootComponent());

	Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	Collision->SetupAttachment(Mesh);
	Collision->SetBoxExtent(FVector(20.f));
	Collision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}


