#include "TickMovingPlatform.h"

ATickMovingPlatform::ATickMovingPlatform()
{
	SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComp"));
	SetRootComponent(SceneComp);
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComp"));
	StaticMeshComp->SetupAttachment(SceneComp);
	
	PrimaryActorTick.bCanEverTick = true;
	MoveSpeed = 100.0f;
	MaxRange = 500.0f;
}
void ATickMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
	Direction = 1.0f;
}

/*void ATickMovingPlatform::Tick(float DeltaTime)어느 순간 제자리에서 무한 떨림
{
	Super::Tick(DeltaTime);
	float DistanceMove = FVector::Dist(StartLocation, GetActorLocation());   DistanceMove값이 한순간 MaxRange를 넘겨 연속적인 +-곱셈이 발생 
	
	if ( DistanceMove >= MaxRange) <-- 오버슛
	{
		Direction *= -1.0f; <-- 떠림
	}
	if (!FMath::IsNearlyZero(MoveSpeed)){
		AddActorWorldOffset(FVector(Direction*MoveSpeed*DeltaTime, 0.0f, 0.0f));
	}
}

void ATickMovingPlatform::Tick(float DeltaTime) // startLocation 기준 앞으로 maxRange만큼 이동
{
	Super::Tick(DeltaTime);
	
	float DistanceMove = FVector::Dist(StartLocation, GetActorLocation());
	
	if ( DistanceMove >= MaxRange)
	{
		Direction *= -1.0f;
		
		float OverShoot = DistanceMove - MaxRange;
		StartLocation = GetActorLocation() -  FVector(Direction * OverShoot, 0.0f, 0.0f);
		
		SetActorLocation(StartLocation);
	}
	if (!FMath::IsNearlyZero(MoveSpeed)){
		AddActorWorldOffset(FVector(Direction*MoveSpeed*DeltaTime, 0.0f, 0.0f));
	}
}*/

void ATickMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	// StartLocation 기준 maxRange만큰 앞뒤로 이동 (부호 있음)
	float CurrentOffset = GetActorLocation().X - StartLocation.X;

	// 양쪽 끝 도달 시 방향 반전 (등호 없이 초과 판정)
	if (CurrentOffset > MaxRange)
	{
		Direction = -1.0f;
	}
	else if (CurrentOffset < -MaxRange)
	{
		Direction = 1.0f;
	}
	//MaxRange를 넘기는 순간 
	if (!FMath::IsNearlyZero(MoveSpeed))
	{
		AddActorWorldOffset(FVector(Direction * MoveSpeed * DeltaTime, 0.0f, 0.0f));
	}
}
/*
void ATickMovingPlatform::StartLogging()
{
	LastLocation = GetActorLocation();
	// GetWorld()가 안전한지 체크
	if (GetWorld())
	{
		GetWorld()->GetTimerManager().SetTimer(LogTimerHandle, this, &AMovingPlatform::LogMovement, LogInterval, true);
		
		GetWorld()->GetTimerManager().SetTimer(TotalDistanceTimerHandle, this, &AMovingPlatform::LogTotalDistance, LogTotal, true);
	}//참고로 a->b()는 사실 (*a).b()의 축약형이에요. 즉 포인터를 역참조(*)해서 객체로 만든 다음 .을 쓰는 것을 한 번에 표현한 거죠.
}
void ATickMovingPlatform::LogMovement()
{
	FVector CurrentLocation = GetActorLocation();
	float DistanceFromOrigin = FMath::Abs(CurrentLocation.Y);

	float DistanceThisTick = FVector::Dist(CurrentLocation, LastLocation);
	TotalDistance += DistanceThisTick;
	LastLocation = CurrentLocation;
	
	
	UE_LOG(LogTemp, Log, TEXT("처음위치부터 이동 거리: %f"), DistanceFromOrigin);
}

void ATickMovingPlatform::LogTotalDistance()
{
	UE_LOG(LogTemp, Warning, TEXT("총 이동 거리: %f"), TotalDistance);
}
*/
