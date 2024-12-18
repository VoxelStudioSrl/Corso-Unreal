// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestDelegate, float, time);

UCLASS()
class CORSO_API ARotatingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARotatingActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RotatingSpeed = 45;

	UPROPERTY(BlueprintAssignable)
	FTestDelegate OnTestDelegate;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UStaticMeshComponent* MeshComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
