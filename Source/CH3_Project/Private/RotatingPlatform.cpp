#include "RotatingPlatform.h"

ARotatingPlatform::ARotatingPlatform()
{
	SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComp"));
	SetRootComponent(SceneComp);
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComp"));
	StaticMeshComp->SetupAttachment(SceneComp);
	
	PrimaryActorTick.bCanEverTick = true;	
	RotationSpeed = 360.0f;
}

void ARotatingPlatform::BeginPlay()
{
	
	Super::BeginPlay();
	
}

void ARotatingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!FMath::IsNearlyZero(RotationSpeed)){
		AddActorLocalRotation(FRotator(0.0f, RotationSpeed*DeltaTime ,0.0f));
	}
}
