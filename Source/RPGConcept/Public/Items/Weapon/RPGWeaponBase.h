// Paul Polbitsev (@evilowl). All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RPGWeaponBase.generated.h"

class UStaticMeshComponent;
class UBoxComponent;

UCLASS()
class RPGCONCEPT_API ARPGWeaponBase : public AActor
{
	GENERATED_BODY()
	
public:	
	ARPGWeaponBase();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UBoxComponent* Collision;
};
