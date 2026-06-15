// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RotatingPlatform.h"
#include "TickRotatingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class CH3_PROJECT_API ATickRotatingPlatform : public ARotatingPlatform
{
	GENERATED_BODY()
public:
	ATickRotatingPlatform();
private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
