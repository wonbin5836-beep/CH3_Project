#pragma once

#include "CoreMinimal.h"
#include "MovingPlatform.h"
#include "TickMovingPlatform.generated.h"

UCLASS()
class CH3_PROJECT_API ATickMovingPlatform : public AMovingPlatform
{
	GENERATED_BODY()
	
public:
	ATickMovingPlatform();
private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};

