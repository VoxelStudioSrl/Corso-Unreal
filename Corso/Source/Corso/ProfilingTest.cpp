#include "ProfilingTest.h"


AProfilingTest::AProfilingTest()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AProfilingTest::BeginPlay()
{
	Super::BeginPlay();
}

void AProfilingTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	BigFunction();
}

void AProfilingTest::BigFunction()
{
	QUICK_SCOPE_CYCLE_COUNTER(STAT_BigFunction);
	FVector sum = FVector::ZeroVector;
	for (int i = 0; i < 1024; i++)
	{
		sum += FVector(1, 1, 1);
	}

	{
		QUICK_SCOPE_CYCLE_COUNTER(STAT_BigFunction_Part2);

		int sum2 = 0;
		for (int i = 0; i < 1024; i++)
		{
			sum2++;
		}
		UE_LOG(LogTemp, Display, TEXT("Sum2=%d"), sum2);
	}
	UE_LOG(LogTemp, Display, TEXT("Sum=%s"), *sum.ToString());
}

