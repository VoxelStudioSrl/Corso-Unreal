#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ArraySpawner.generated.h"

class ARotatingActor;

UCLASS()
class CORSO_API AArraySpawner : public AActor
{
	GENERATED_BODY()
	
public:
	AArraySpawner();

	float time = 0;

	UPROPERTY(EditAnywhere)
	int32 SpawnCount;

	UPROPERTY(EditAnywhere)
	AActor* SpawnOrigin;

	UPROPERTY(EditAnywhere)
	TSubclassOf<ARotatingActor> SpawnClass;

	UPROPERTY()
	TArray<ARotatingActor*> SpawnedActors;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
