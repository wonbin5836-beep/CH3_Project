#include "TimerMovingPlatform.h"

ATimerMovingPlatform::ATimerMovingPlatform()
{
	SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComp2"));
	SetRootComponent(SceneComp);
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComp2"));
	StaticMeshComp->SetupAttachment(SceneComp);
	
	PrimaryActorTick.bCanEverTick = false;
	MoveSpeed = 100.0f;
	MaxRange = 500.0f;
}
void ATimerMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	LastTime = GetWorld()->GetTimeSeconds();
	StartLocation = GetActorLocation();
	Direction = 1.0f;
	if (GetWorld())
	{
		GetWorld()->GetTimerManager().SetTimer(MovingHandle, this, &ATimerMovingPlatform::MoveStep, 0.008f, true);
		GetWorld()->GetTimerManager().SetTimer(HideHandle, this, &ATimerMovingPlatform::TogglePlatformVisibility, 10.0f, true);
		
	}
}
void ATimerMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);	
}

void ATimerMovingPlatform::MoveStep()
{
	float CurrentTime = GetWorld()->GetTimeSeconds();
	float CustomDeltaTime = CurrentTime - LastTime;
	LastTime = CurrentTime;
	
	float CurrentLocation = GetActorLocation().Y - StartLocation.Y; 
	
	if (CurrentLocation > MaxRange)
	{
		Direction = -1.0f;
	}else if (CurrentLocation < 0.0f)
	{
		Direction = 1.0f;
	}
	
	AddActorWorldOffset(FVector(0.0f,Direction*MoveSpeed*CustomDeltaTime,0.0f));
}

void ATimerMovingPlatform::TogglePlatformVisibility()
{
	bIsPlatformVisible = !bIsPlatformVisible;

	if (bIsPlatformVisible)
	{
		Show();
	}
	else
	{
		Hide();
	}
}

void ATimerMovingPlatform::Show()
{
	SetActorHiddenInGame(false);      
	SetActorEnableCollision(true);  
}

void ATimerMovingPlatform::Hide()
{
	SetActorHiddenInGame(true);    
	SetActorEnableCollision(false); 
}