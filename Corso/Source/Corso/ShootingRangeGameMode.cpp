#include "ShootingRangeGameMode.h"

#include "ShootingTarget.h"
#include "Kismet/GameplayStatics.h"

AShootingRangeGameMode::AShootingRangeGameMode()
{
	PrimaryActorTick.bCanEverTick = true;
	activated = false;
	timer = 0;
	score = 0;
}

void AShootingRangeGameMode::BeginPlay()
{
	Super::BeginPlay();

	// disable all targets
	SwitchTargets(false);
}

void AShootingRangeGameMode::StartMinigame()
{
	timer = 30;
	score = 0;
	activated = true;
	SwitchTargets(true);
}

void AShootingRangeGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (activated)
	{
		timer -= DeltaSeconds;
		FTimespan t = FTimespan::FromSeconds(timer);
		FString text = FString::Printf(TEXT("%d.%03d"), t.GetSeconds(), t.GetFractionMilli());
		OnTimerChanged(text);

		if (timer <= 0)
		{
			timer = 0;
			OnTimerChanged(TEXT("0.000"));
			StopMinigame();
		}
	}
}

void AShootingRangeGameMode::OnTargetHit(int32 _score)
{
	score += _score;
	OnScoreChanged(score);
}

void AShootingRangeGameMode::StopMinigame()
{
	activated = false;
	SwitchTargets(false);
}

void AShootingRangeGameMode::SwitchTargets(bool targetsEnabled)
{
	TArray<AActor*> targets;
	UGameplayStatics::GetAllActorsOfClass(this, AShootingTarget::StaticClass(), targets);

	for (auto actor : targets)
	{
		auto target = Cast<AShootingTarget>(actor);
		if (target)
		{
			target->SwitchState(targetsEnabled, true);
		}
	}
}
