#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "ShootingRangeGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CORSO_API AShootingRangeGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AShootingRangeGameMode();
	
	UFUNCTION(BlueprintCallable)
	void StartMinigame();
	void OnTargetHit(int32 score);
	void StopMinigame();

	/// Switch target status (rotated or not)
	void SwitchTargets(bool targetsEnabled);

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	// update UI in blueprint
	UFUNCTION(BlueprintImplementableEvent)
	void OnScoreChanged(int32 newScore);
	UFUNCTION(BlueprintImplementableEvent)
	void OnTimerChanged(const FString& text);

private:
	bool activated;
	int32 score;
	float timer;
};
