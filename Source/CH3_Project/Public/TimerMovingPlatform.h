#pragma once

#include "CoreMinimal.h"
#include "MovingPlatform.h"
#include "TimerMovingPlatform.generated.h"

UCLASS()
class CH3_PROJECT_API ATimerMovingPlatform : public AMovingPlatform
{
	GENERATED_BODY()

public:
	ATimerMovingPlatform();
private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
	float LastTime;
	
	void MoveStep();
	
	FTimerHandle MovingHandle;
	FTimerHandle HideHandle;
	bool bIsPlatformVisible = true;  

	void TogglePlatformVisibility();
	void Hide();
	void Show();
	//test
};
