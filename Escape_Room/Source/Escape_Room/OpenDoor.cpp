// Copyright Artem Gerasimov 2018

#include "OpenDoor.h"
#include "Gameframework/Actor.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	actorOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
	
}

void UOpenDoor::openDoor()
{
	FRotator newRot = FRotator(0.0f, openAngle, 0.0f);
	owner->SetActorRotation(newRot, ETeleportType::TeleportPhysics);
}

void UOpenDoor::closeDoor()
{
	FRotator newRot = FRotator(0.0f, 90.0f, 0.0f);
	owner->SetActorRotation(newRot, ETeleportType::TeleportPhysics);
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (pressurePlate->IsOverlappingActor(actorOpens)) {
		openDoor();
		lastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}
	else if (!pressurePlate->IsOverlappingActor(actorOpens) && GetWorld()->GetTimeSeconds() - lastDoorOpenTime > doorCloseDelay) {
		closeDoor();
	}
}

