#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlatformSpawner.generated.h"

class ATimerMovingPlatform;

UCLASS()
class CH3_PROJECT_API APlatformSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	APlatformSpawner();

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<ATimerMovingPlatform> PlatformClass; 

	UPROPERTY(EditAnywhere)
	int32 SpawnCount = 5; 
};
