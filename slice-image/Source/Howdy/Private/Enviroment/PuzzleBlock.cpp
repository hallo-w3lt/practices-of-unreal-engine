/*
 *  Developed by IT&feel CA
 *  Author: @itandfeel
 *  Designer: Thamesis Marrero @thamesis09
 *  Programmer: Victor Dominguez @hallo_w3lt
 */

#include "PuzzleBlock.h"

#include "GameHUD.h"
#include "GridWidget.h"
#include "UObject/ConstructorHelpers.h"
#include "HowdyGameMode.h"
#include "HowdyGameState.h"
#include "HowdyPlayerController.h"
#include "PuzzleGrid.h"
#include "WidgetComponent.h"
#include "Camera/CameraActor.h"
#include "Components/BoxComponent.h"
#include "Materials/MaterialInstance.h"
#include "Camera/CameraComponent.h"

APuzzleBlock::APuzzleBlock(const FObjectInitializer& ObjectInitializer) : AActor(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;

	struct FConstructorStatics
	{
		ConstructorHelpers::FObjectFinderOptional<UStaticMesh> DefaultMesh;
		ConstructorHelpers::FObjectFinderOptional<UMaterialInstance> PuzzleMaterial;

		FConstructorStatics() : DefaultMesh(TEXT("StaticMesh'/Game/Meshes/SM_PuzzleCube.SM_PuzzleCube'")),
		                        PuzzleMaterial(TEXT("/Game/Base/Materials/MI_Puzzle.MI_Puzzle"))
		{
			// ...
		}
	};

	static FConstructorStatics ConstructorStatics;
	PuzzleMaterialInstance = ConstructorStatics.PuzzleMaterial.Get();

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	RootComponent = SceneComponent;

	PlaneMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlaneMesh"));
	PlaneMesh->SetStaticMesh(ConstructorStatics.DefaultMesh.Get());
	PlaneMesh->SetRelativeScale3D(FVector(1.f, 1.f, 0.001f));
	PlaneMesh->SetRelativeLocation(FVector(0.f, 0.f, 25.f));
	PlaneMesh->SetMaterial(0, PuzzleMaterialInstance);
	PlaneMesh->SetupAttachment(SceneComponent);

	BodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BodyMesh"));
	BodyMesh->SetStaticMesh(ConstructorStatics.DefaultMesh.Get());
	BodyMesh->SetRelativeScale3D(FVector(1.f, 1.f, 0.1f));
	BodyMesh->SetRelativeLocation(FVector(0.f, 0.f, 0.f));
	BodyMesh->SetupAttachment(SceneComponent);

	PlaneMesh->OnClicked.AddDynamic(this, &APuzzleBlock::OnClickedBlock);
	PlaneMesh->OnInputTouchBegin.AddDynamic(this, &APuzzleBlock::OnFingerPressedBlock);
}

APuzzleBlock::~APuzzleBlock()
{
	// ...
}

// void APuzzleBlock::NotifyActorBeginOverlap(AActor* OtherActor)
// {
// 	if (OtherActor != nullptr && OtherActor != this && bCanDragging && !bOverlapped)
// 	{
// 		auto* Overlapped = Cast<APuzzleBlock>(OtherActor);
// 		if (Overlapped != nullptr && !Overlapped->bOverlapped)
// 		{
// 			Overlapped->GetMaterialInstanceDynamic()->SetScalarParameterValue("LerpStrength", 1.f);
// 		}
// 	}
// }

// void APuzzleBlock::NotifyActorEndOverlap(AActor* OtherActor)
// {
// 	if (OtherActor != nullptr && OtherActor != this && bCanDragging)
// 	{
// 		auto* Overlapped = Cast<APuzzleBlock>(OtherActor);
// 		if (Overlapped != nullptr)
// 		{
// 			Overlapped->GetMaterialInstanceDynamic()->SetScalarParameterValue("LerpStrength", 0.f);
// 		}
// 	}
// }

void APuzzleBlock::BeginPlay()
{
	Super::BeginPlay();

	if (nullptr != GetWorld()) { HowdyGameMode = GetWorld()->GetAuthGameMode<AHowdyGameMode>(); }
	if (nullptr != HowdyGameMode) { HowdyGameState = HowdyGameMode->GetGameState<AHowdyGameState>(); }
	if (nullptr == HowdyGameState) { return; }
	PlayerController = Cast<AHowdyPlayerController>(GetWorld()->GetFirstPlayerController());

	if (nullptr == PlayerController) { return; }
	if (nullptr == PuzzleMaterialInstance) { return; }
	PuzzleMaterialInstanceDynamic = PlaneMesh->CreateDynamicMaterialInstance(0, PuzzleMaterialInstance);

	if (nullptr == PuzzleMaterialInstanceDynamic) { return; }

	PuzzleMaterialInstanceDynamic->SetScalarParameterValue("CustomU", MaterialParameter.U);
	PuzzleMaterialInstanceDynamic->SetScalarParameterValue("CustomV", MaterialParameter.V);
	PuzzleMaterialInstanceDynamic->SetScalarParameterValue("Size", MaterialParameter.Size);
	PuzzleMaterialInstanceDynamic->SetScalarParameterValue("Saturation", MaterialParameter.Saturation);

	PlaneMesh->SetMaterial(0, PuzzleMaterialInstanceDynamic);

	PlayerController = Cast<AHowdyPlayerController>(GetWorld()->GetFirstPlayerController());
	HUD = Cast<AGameHUD>(PlayerController->GetHUD());

	//#if !UE_BUILD_SHIPPING
	//	FVector drawPos(FVector::ZeroVector);
	//	FColor drawColor = FLinearColor(250.f, 216.f, 89.f, 1.f).ToFColor(true);
	//	float drawDuration = 200.f;
	//	bool drawShadow = true;
	//	DrawDebugString(GetWorld(), drawPos, *FString::Printf(TEXT("%s [%d]"), TEXT("index: "), GetIndex()), this, drawColor, drawDuration, drawShadow);
	//#endif
}

void APuzzleBlock::Tick(const float InDeltaTime)
{
	Super::Tick(InDeltaTime);

	if (!bCanDragging || !bDragging || nullptr == PlayerController || nullptr == HUD) { return; }

	if (PlayerController->IsInputKeyDown(FKey("LeftMouseButton")) && HowdyGameState->IsGamePaying())
	{
		PlayerController->SetViewTargetWithBlend(CameraActor);

		FVector WorldLocation{}, WorldDirection{};
		PlayerController->DeprojectMousePositionToWorld(WorldLocation, WorldDirection);

		const FVector Location{WorldDirection * ScopeCamera + WorldLocation};
		SetActorRelativeLocation(Location);
	}
	else
	{		
		const FCollisionQueryParams CollisionParams;

		bHitting = OutHit.bBlockingHit;
		PuzzleBlockOverlapped = Cast<APuzzleBlock>(OutHit.GetActor());

		bDragging = false;
		OnDragging.Broadcast(false);

		HUD->GetGridWidget()->SetVisibility(ESlateVisibility::Visible);

		if (!bOverlapped && PuzzleBlockOverlapped != nullptr && PuzzleBlockOverlapped->GetIndex() == Index)
		{
			if (auto* Material{PuzzleBlockOverlapped->GetMaterialInstanceDynamic()}; Material != nullptr)
			{
				Material->SetScalarParameterValue("Saturation", 1);
			}

			PuzzleBlockOverlapped->bOverlapped = true;
			if (OwningGrid->IncrementOverlappedBlocks() >= OwningGrid->GetSize()) { HowdyGameState->FinishGame(); }

			Destroy();
		}
		else
		{
			SetActorRelativeLocation(OriginLocation);
		}

		PlayerController->SetViewTargetWithBlend(CameraActor);
		CameraActor->GetCameraComponent()->SetFieldOfView(110.f);
	}
}

void APuzzleBlock::SetOwningGrid(APuzzleGrid* InPuzzleBlockGrid)
{
	if (nullptr == InPuzzleBlockGrid) { return; }
	OwningGrid = InPuzzleBlockGrid;
}

void APuzzleBlock::SetMaterialParameter(const FMaterialParametersStruct& InValue) { MaterialParameter = InValue; }

void APuzzleBlock::OnClickedBlock(UPrimitiveComponent* ClickedComponent, FKey ButtonClicked) { HandleClicked(); }

void APuzzleBlock::OnFingerPressedBlock(ETouchIndex::Type FingerIndex, UPrimitiveComponent* TouchedComponent)
{
	HandleClicked();
}

void APuzzleBlock::HandleClicked()
{
	if (!bCanDragging || !HowdyGameState->IsGamePaying()) { return; }

	bDragging = true;
	OnDragging.Broadcast(true);

	CameraActor->GetCameraComponent()->SetFieldOfView(90.f);

	if (FVector::ZeroVector == OriginLocation)
	{
		OriginLocation = GetActorLocation();
	}
}
