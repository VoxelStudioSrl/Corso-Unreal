// Fill out your copyright notice in the Description page of Project Settings.


#include "RotatingActor.h"

// Sets default values
ARotatingActor::ARotatingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
}

// Called when the game starts or when spawned
void ARotatingActor::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Error, TEXT("Hello from Rotating Actor"));
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(1, 1, FColor::Red, FString::Printf(TEXT("Hello on screen")));
	}
}

// Called every frame
void ARotatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(FRotator(RotatingSpeed * DeltaTime, 0, 0));

	OnTestDelegate.Broadcast(DeltaTime);
}

