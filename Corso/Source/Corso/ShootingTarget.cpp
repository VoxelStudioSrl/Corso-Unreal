#include "ShootingTarget.h"

#include "ShootingRangeGameMode.h"
#include "TargetData.h"
#include "Kismet/GameplayStatics.h"

AShootingTarget::AShootingTarget()
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RotationRoot = CreateDefaultSubobject<USceneComponent>(TEXT("RotationRoot"));
	RotationRoot->SetupAttachment(RootComponent);
	TargetMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TargetMesh"));
	TargetMesh->SetupAttachment(RotationRoot);
}

void AShootingTarget::BeginPlay()
{
	Super::BeginPlay();

	if (!TargetData)
	{
		UE_LOG(LogTemp, Error, TEXT("[ShootingTarget] Target data not set!"))
		return;
	}
	TargetMesh->OnComponentHit.AddDynamic(this, &AShootingTarget::OnHit);
	LoadTexture();
}

void AShootingTarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AShootingTarget::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{
	if (!bTargetEnabled)
	{
		return;
	}
	UE_LOG(LogTemp, Display, TEXT("Target Hit!"))

	bTargetEnabled = false;
	DisableAnimation(false);

	auto gm = Cast<AShootingRangeGameMode>(UGameplayStatics::GetGameMode(this));
	if (gm)
	{
		gm->OnTargetHit(TargetData->Score);
	}
}

void AShootingTarget::SwitchState(bool enableTarget, bool disableReset)
{
	bTargetEnabled = enableTarget;
	if (enableTarget)
	{
		EnableAnimation();
	} else
	{
		DisableAnimation(disableReset);
	}
}

void AShootingTarget::LoadTexture()
{
	auto texture = TargetData->Texture.LoadSynchronous();
	UMaterialInstanceDynamic* mi = UMaterialInstanceDynamic::Create(TargetMesh->GetMaterial(0), this);
	mi->SetTextureParameterValue(FName("TextureParam"), texture);

	TargetMesh->SetMaterial(0, mi);
}
