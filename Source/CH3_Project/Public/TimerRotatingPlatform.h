#pragma once

#include "CoreMinimal.h"
#include "RotatingPlatform.h"
#include "TimerRotatingPlatform.generated.h"

UCLASS()
class CH3_PROJECT_API ATimerRotatingPlatform : public ARotatingPlatform
{
	GENERATED_BODY()
	
public:
	ATimerRotatingPlatform();
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Timer")
	float SpawnTimer;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="HideTime")
	float HideTimer;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Move")
	float SpawnOffset ;
private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
	float LastTime;
	void Rotate();
	
	FTimerHandle RotatingHandle;
	FTimerHandle HideHandle;
	bool bIsPlatformVisible = true;  

	void TogglePlatformVisibility();
	void Hide();
	void Show();
};
