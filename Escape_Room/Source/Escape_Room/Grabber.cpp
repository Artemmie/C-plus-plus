// Copyright Artem Gerasimov 2018

#include "Grabber.h"
#define OUT

UGrabber::UGrabber()
{
	PrimaryComponentTick.bCanEverTick = true;
}
// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
	PhysicsHandleComponent();
	InputComponent();
}

void UGrabber::PhysicsHandleComponent()
{
	physicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (physicsHandle == nullptr) UE_LOG(LogTemp, Error, TEXT("%s missing physics handle component"), *GetOwner()->GetName());
}
void UGrabber::InputComponent()
{
	if (physicsHandle == nullptr) UE_LOG(LogTemp, Error, TEXT("%s missing input component"), *GetOwner()->GetName());
	inputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (!inputComponent) return;
	if (inputComponent)
	{
		inputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
		inputComponent->BindAction("Grab", IE_Released, this, &UGrabber::Release);
	}
}

void UGrabber::Grab()
{
	auto hitResult = ReachTarget();
	auto componentToGrab = hitResult.GetComponent();
	auto actorHit = hitResult.GetActor();
	if (actorHit)
	{
		if (!physicsHandle) return;
		physicsHandle->GrabComponentAtLocationWithRotation(
			componentToGrab,
			NAME_None,
			componentToGrab->GetOwner()->GetActorLocation(),
			componentToGrab->GetOwner()->GetActorRotation()
		);
	}
}
void UGrabber::Release()
{
	if (!physicsHandle) return;
	physicsHandle->ReleaseComponent();
}
// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	if (!physicsHandle) return;
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (physicsHandle->GrabbedComponent) physicsHandle->SetTargetLocation(GetLineTracePoints().v2);

}

FHitResult UGrabber::ReachTarget() const
{
	FHitResult hitResult;
	FTwoVectors tracePoints = GetLineTracePoints();
	FCollisionQueryParams traceParam(FName(""), false, GetOwner());
	GetWorld()->LineTraceSingleByObjectType(
		OUT hitResult,
		tracePoints.v1, ///Start
		tracePoints.v2, ///End
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		traceParam
	);

	return hitResult;
}

FTwoVectors UGrabber::GetLineTracePoints() const
{
	FVector StartLocation;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT StartLocation,
		OUT PlayerViewPointRotation
	);
	FVector EndLocation = StartLocation + PlayerViewPointRotation.Vector() * reach;
	return FTwoVectors(StartLocation, EndLocation);
}