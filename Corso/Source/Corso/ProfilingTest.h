// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProfilingTest.generated.h"

UCLASS()
class CORSO_API AProfilingTest : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AProfilingTest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void BigFunction();
};
