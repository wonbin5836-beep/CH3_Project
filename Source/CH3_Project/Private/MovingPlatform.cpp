#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	
	
	PrimaryActorTick.bCanEverTick = false;
	MoveSpeed = 100.0f;
	MaxRange = 500.0f;
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
}
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}
void AMovingPlatform::StartLogging()
{
	LastLocation = GetActorLocation();
	// GetWorld()가 안전한지 체크
	if (GetWorld())
	{
		GetWorld()->GetTimerManager().SetTimer(LogTimerHandle, this, &AMovingPlatform::LogMovement, LogInterval, true);
		
		GetWorld()->GetTimerManager().SetTimer(TotalDistanceTimerHandle, this, &AMovingPlatform::LogTotalDistance, LogTotal, true);
	}//참고로 a->b()는 사실 (*a).b()의 축약형이에요. 즉 포인터를 역참조(*)해서 객체로 만든 다음 .을 쓰는 것을 한 번에 표현한 거죠.
}
void AMovingPlatform::LogMovement()
{
	FVector CurrentLocation = GetActorLocation();
	float DistanceFromOrigin = FMath::Abs(CurrentLocation.Y);

	float DistanceThisTick = FVector::Dist(CurrentLocation, LastLocation);
	TotalDistance += DistanceThisTick;
	LastLocation = CurrentLocation;
	
	
	UE_LOG(LogTemp, Log, TEXT("처음위치부터 이동 거리: %f"), DistanceFromOrigin);
}

void AMovingPlatform::LogTotalDistance()
{
	UE_LOG(LogTemp, Warning, TEXT("총 이동 거리: %f"), TotalDistance);
}
