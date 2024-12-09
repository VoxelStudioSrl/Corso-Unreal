#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Interactable.h"
#include "PlayerInteractionComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CORSO_API UPlayerInteractionComponent : public USceneComponent
{
	GENERATED_BODY()

public:
	UPlayerInteractionComponent();

	UPROPERTY(BlueprintReadWrite)
	TScriptInterface<IInteractable> CurrentInteractable;

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void InteractPressed();
};
