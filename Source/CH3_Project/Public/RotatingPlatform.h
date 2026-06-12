#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingPlatform.generated.h"

UCLASS()
class CH3_PROJECT_API ARotatingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	ARotatingPlatform();

protected:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Rotation|Components")
	USceneComponent* SceneComp;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Rotation|Components")
	UStaticMeshComponent* StaticMeshComp;
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Rotation")
	float RotationSpeed;
};
