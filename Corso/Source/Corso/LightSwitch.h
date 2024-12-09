#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "UObject/Object.h"
#include "LightSwitch.generated.h"

/**
 * 
 */
UCLASS()
class CORSO_API ALightSwitch : public AActor, public IInteractable
{
	GENERATED_BODY()

public:
	ALightSwitch();

	UPROPERTY(EditAnywhere)
	AActor* Light;

	virtual void Interact() override;
};
