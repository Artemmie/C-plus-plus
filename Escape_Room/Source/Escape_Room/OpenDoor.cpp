// Copyright Artem Gerasimov 2018

#include "OpenDoor.h"
#include "Gameframework/Actor.h"
#include "Engine/World.h"

UOpenDoor::UOpenDoor()
{
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	actorOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!pressurePlate) UE_LOG(LogTemp, Error, TEXT("Pressure plate volume is missing in the scene/script."));
	if (!statue) UE_LOG(LogTemp, Error, TEXT("Statue is missing in the script/scene."));

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


void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (!pressurePlate || !statue) return;
	if (pressurePlate->IsOverlappingActor(actorOpens) || pressurePlate->IsOverlappingActor(statue)) {
		openDoor();
		lastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}
	else if ((!pressurePlate->IsOverlappingActor(actorOpens) || !pressurePlate->IsOverlappingActor(statue)) && GetWorld()->GetTimeSeconds() - lastDoorOpenTime > doorCloseDelay) {
		closeDoor();
	}
}

