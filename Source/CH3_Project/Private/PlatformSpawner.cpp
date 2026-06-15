#include "PlatformSpawner.h"

#include "TimerMovingPlatform.h"

APlatformSpawner::APlatformSpawner()
{

}

void APlatformSpawner::BeginPlay()
{
	Super::BeginPlay();
	if (!PlatformClass) return;

	for (int32 i = 0; i < SpawnCount; i++)
	{
		// 랜덤 위치
		FVector SpawnLocation = GetActorLocation() + FVector(
			FMath::RandRange(0.0f, 200.0f),// X: 랜덤
			i*600.0f, // Y: 일정 간격
			FMath::RandRange(0.0f, 300.0f)     // Z: 랜덤 높이
			);
		FRotator SpawnRotarion = GetActorRotation() + FRotator(
				0.0f,
				FMath::RandRange(-45.0f, 45.0f), 
				0.0f     
			);

		FActorSpawnParameters Params;
		Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		ATimerMovingPlatform* Platform = GetWorld()->SpawnActor<ATimerMovingPlatform>(
			PlatformClass,
			SpawnLocation,
			SpawnRotarion,
			Params
		);

		if (Platform)
		{
			// 랜덤 속성 부여
			Platform->MoveSpeed = FMath::RandRange(50.0f, 300.0f);
			Platform->MaxRange  = FMath::RandRange(200.0f, 800.0f);
			Platform->HideTimer = FMath::RandRange(0.0f, 0.0f);
		}
	}
}


