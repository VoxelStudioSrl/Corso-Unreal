#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ShootingTarget.generated.h"

UCLASS()
class CORSO_API AShootingTarget : public AActor
{
	GENERATED_BODY()

public:
	AShootingTarget();

	/// false if the target is hidden (rotated) and disabled
	UPROPERTY(BlueprintReadWrite)
	bool bTargetEnabled;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UTargetData* TargetData;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	USceneComponent* RotationRoot;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* TargetMesh;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		FVector NormalImpulse, const FHitResult& Hit);

	// Apply rotation in blueprint
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void DisableAnimation(bool disableReset);
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void EnableAnimation();

	UFUNCTION(BlueprintCallable)
	void SwitchState(bool enableTarget, bool disableReset = false);

private:
	void LoadTexture();
};
