#include "PlayerInteractionComponent.h"

// Sets default values for this component's properties
UPlayerInteractionComponent::UPlayerInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UPlayerInteractionComponent::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void UPlayerInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FHitResult hit;
	auto start = GetComponentLocation();
	FVector end = GetComponentLocation() + GetForwardVector() * 1000.f;

	FColor drawColor = FColor::Green;
	if (GetWorld()->LineTraceSingleByChannel(hit, start, end, ECC_Visibility))
	{
		drawColor = FColor::Red;
		DrawDebugSphere(GetWorld(), hit.Location, 15, 16, drawColor);
	}
	DrawDebugLine(GetWorld(), start, end, drawColor);
	auto actor = hit.GetActor();
	IInteractable* interactable = Cast<IInteractable>(actor);
	if (interactable)
	{
		CurrentInteractable = actor;
	}
}

void UPlayerInteractionComponent::InteractPressed()
{
	if (CurrentInteractable)
	{
		CurrentInteractable->Interact();
	}
}

