// Copyright Artem Gerasimov 2018

#include "Grabber.h"
#include "Gameframework/Actor.h"
#include "Engine/World.h"

#define OUT
// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	FString objectName = GetOwner()->GetName();
	FString objectPos = GetOwner()->GetTransform().GetLocation().ToString();
	UE_LOG(LogTemp, Warning, TEXT("Position report on %s at %s"), *objectName, *objectPos);

	// ...
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	FVector playerViewPointLocation;
	FRotator playerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT playerViewPointLocation, OUT playerViewPointRotation);

	UE_LOG(LogTemp, Warning, TEXT("View Point Location: %s,  View Point Rotation: %s"), *playerViewPointLocation.ToString(), *playerViewPointRotation.ToString());
	// ...
}

