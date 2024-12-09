#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "TargetData.generated.h"

/**
 * 
 */
UCLASS()
class CORSO_API UTargetData : public UDataAsset
{
	GENERATED_BODY()

public:
	UTargetData() = default;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TargetData")
	float ResetDelay = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TargetData")
	int32 Score = 1;

	/// Load texture later
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TargetData")
	TSoftObjectPtr<UTexture2D> Texture;
};
