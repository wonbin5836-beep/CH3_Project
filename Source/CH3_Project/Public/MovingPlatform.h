#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class CH3_PROJECT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	AMovingPlatform();
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Move")
	float MoveSpeed;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Move")
	float MaxRange;
protected:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Move|Components")
	USceneComponent* SceneComp;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Item|Components")
	UStaticMeshComponent* StaticMeshComp;
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
	
	float Direction = 1.0f;
	
	FVector StartLocation;
	
	FTimerHandle LogTimerHandle;
	FTimerHandle TotalDistanceTimerHandle;
	float LogInterval = 0.5f; // 로그 출력 주기 (초)
	float LogTotal = 10.0f;
	float TotalDistance = 0.0f;
	FVector LastLocation;
	
	void StartLogging();
	void LogMovement();
	void LogTotalDistance();
	
};
