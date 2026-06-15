#include "TimerRotatingPlatform.h"

ATimerRotatingPlatform::ATimerRotatingPlatform()
{
	SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComp2"));
	SetRootComponent(SceneComp);
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComp2"));
	StaticMeshComp->SetupAttachment(SceneComp);
	
	PrimaryActorTick.bCanEverTick = false;
	RotationSpeed = 360.0f;
	SpawnTimer = 0.008f;
	HideTimer = 5.0f;
	SpawnOffset  = 100.0f;	
}

void ATimerRotatingPlatform::BeginPlay()
{
	Super::BeginPlay();
	if (GetWorld())
	{
		GetWorld()->GetTimerManager().SetTimer(
			RotatingHandle,
			this,
			&ATimerRotatingPlatform::Rotate,
			SpawnTimer,
			true);
		GetWorld()->GetTimerManager().SetTimer(
			HideHandle,
			this, 
			&ATimerRotatingPlatform::TogglePlatformVisibility,
			HideTimer,
			true);
	}
	
	if (GetOwner() ==nullptr)
	{
		FVector SpawnLocation = GetActorLocation() + FVector(SpawnOffset, 0.0f, 0.0f);
		FRotator SpawnRotation = GetActorRotation();
		
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this; 
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		
		ATimerRotatingPlatform* SpawnedPlatform = (ATimerRotatingPlatform*) GetWorld()->SpawnActor<ATimerRotatingPlatform>(
			ATimerRotatingPlatform::StaticClass(),
			SpawnLocation,
			SpawnRotation,
			SpawnParams);
		if (SpawnedPlatform)
		{
			// C++ StaticClass로 스폰하면 메시가 안 보일 수 있으므로 원본의 스태틱 메시와 스케일을 복사해줍니다.
			if (StaticMeshComp && SpawnedPlatform->StaticMeshComp)
			{
				SpawnedPlatform->StaticMeshComp->SetStaticMesh(StaticMeshComp->GetStaticMesh());
				SpawnedPlatform->SetActorScale3D(GetActorScale3D());
				UMaterialInterface* Material = StaticMeshComp->GetMaterial(0);
				SpawnedPlatform->StaticMeshComp->SetMaterial(0,Material);
			}
			SpawnedPlatform->RotationSpeed = RotationSpeed;
			SpawnedPlatform->HideTimer = HideTimer;
			SpawnedPlatform->SpawnTimer = SpawnTimer;
			SpawnedPlatform->GetWorld()->GetTimerManager().SetTimer(
				SpawnedPlatform->RotatingHandle,
				SpawnedPlatform,
				&ATimerRotatingPlatform::Rotate,
				SpawnTimer,
				true);
			
			SpawnedPlatform->bIsPlatformVisible = false; //번걸아가며 hide
			SpawnedPlatform->Hide();
			
			SpawnedPlatform->GetWorld()->GetTimerManager().SetTimer( // 원본 hide와 시간차
				SpawnedPlatform->HideHandle,
				SpawnedPlatform,
				&ATimerRotatingPlatform::TogglePlatformVisibility,
				HideTimer,true
				);
		}
	}
}
void ATimerRotatingPlatform::Rotate()
{
	float CurrentTime = GetWorld()->GetTimeSeconds();
	float CustomDeltaTime = CurrentTime - LastTime;
	LastTime = CurrentTime;
	
	AddActorLocalRotation(FRotator(0.0f, RotationSpeed*CustomDeltaTime ,0.0f));
}

void ATimerRotatingPlatform::TogglePlatformVisibility()
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

void ATimerRotatingPlatform::Show()
{
	SetActorHiddenInGame(false);      
	SetActorEnableCollision(true);  
}

void ATimerRotatingPlatform::Hide()
{
	SetActorHiddenInGame(true);    
	SetActorEnableCollision(false); 
}

void ATimerRotatingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}