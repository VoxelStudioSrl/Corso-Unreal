#include "Door.h"

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (animating)
	{
		float angle = FMath::Lerp(startAngle, endAngle, animTimer / animDuration);
		SetActorRotation(FRotator(0, angle, 0));
		animTimer += DeltaTime;

		if (animTimer >= animDuration)
		{
			animating = false;
			animTimer = 0;
		}
	}
}

void ADoor::Interact()
{
	UE_LOG(LogTemp, Display, TEXT("Door Interact"));
	animating = true;
	open = !open;
	if (open)
	{
		startAngle = 0;
		endAngle = 90;
	}
	else
	{
		startAngle = 90;
		endAngle = 0;
	}
}

void ADoor::InteractBP_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("Interact c++"));
}

