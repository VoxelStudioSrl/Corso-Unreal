#include "PlayerInteractionComponent.h"

#include "Kismet/KismetSystemLibrary.h"

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
	FVector end = GetComponentLocation() + GetForwardVector() * 100.f;

	FColor drawColor = FColor::Green;
	if (GetWorld()->LineTraceSingleByChannel(hit, start, end, ECC_Visibility))
	{
		drawColor = FColor::Red;
		DrawDebugSphere(GetWorld(), hit.Location, 5, 16, drawColor);
	}
	DrawDebugLine(GetWorld(), start, end, drawColor);
	auto actor = hit.GetActor();

	// fix for blueprint only actors
	if (UKismetSystemLibrary::DoesImplementInterface(actor, UInteractable::StaticClass()))
	{
		CurrentInteractable = actor;
	}
	else
	{
		CurrentInteractable = nullptr;
	}
}

void UPlayerInteractionComponent::InteractPressed()
{
	if (CurrentInteractable)
	{
		CurrentInteractable->Interact();
	}
	// fix for blueprint only actors
	else if (CurrentInteractable.GetObject())
	{
		IInteractable::Execute_InteractBP(CurrentInteractable.GetObject());
	}
}

