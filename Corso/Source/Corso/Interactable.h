#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interactable.generated.h"

// This class does not need to be modified.
UINTERFACE(Blueprintable)
class UInteractable : public UInterface
{
	GENERATED_BODY()
};

class CORSO_API IInteractable
{
	GENERATED_BODY()
	
public:
	virtual void Interact() = 0;
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void InteractBP();
};
