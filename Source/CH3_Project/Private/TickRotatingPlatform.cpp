// Fill out your copyright notice in the Description page of Project Settings.


#include "TickRotatingPlatform.h"

ATickRotatingPlatform::ATickRotatingPlatform()
{
	SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComp"));
	SetRootComponent(SceneComp);
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComp"));
	StaticMeshComp->SetupAttachment(SceneComp);
	
	PrimaryActorTick.bCanEverTick = true;	
	RotationSpeed = 360.0f;
}

void ATickRotatingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATickRotatingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!FMath::IsNearlyZero(RotationSpeed)){
		AddActorLocalRotation(FRotator(0.0f, RotationSpeed*DeltaTime ,0.0f));
	}
}