#include "ArraySpawner.h"
#include "RotatingActor.h"

// Sets default values
AArraySpawner::AArraySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AArraySpawner::BeginPlay()
{
	Super::BeginPlay();
	
	if (!SpawnOrigin)
	{
		UE_LOG(LogTemp, Error, TEXT("Spawn origin not set!"));
		return;
	}
	for (int i = 0; i < SpawnCount; i++)
	{
		FVector pos = SpawnOrigin->GetActorLocation() + FVector(0, 120 * i, 0);
		auto actor = GetWorld()->SpawnActor<ARotatingActor>(SpawnClass, pos, FRotator::ZeroRotator);
		SpawnedActors.Add(actor);
	}
}

// Called every frame
void AArraySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	time += DeltaTime;

	for (auto actor : SpawnedActors)
	{
		FVector offset(0, 0, FMath::Sin(time) * 2.f);
		actor->AddActorWorldOffset(offset);
	}
}

