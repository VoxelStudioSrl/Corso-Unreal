#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"
#include "Door.generated.h"

UCLASS()
class CORSO_API ADoor : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:
	ADoor();

	bool open = false;
	bool animating = false;
	float animDuration = 1.f;
	float animTimer = 0;
	float startAngle = 0;
	float endAngle = 90;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void Interact() override;
	virtual void InteractBP_Implementation() override;
};
