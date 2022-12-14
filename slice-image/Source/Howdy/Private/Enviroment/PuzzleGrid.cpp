/*
 *  Developed by IT&feel CA
 *  Author: @itandfeel
 *  Designer: Thamesis Marrero @thamesis09
 *  Programmer: Victor Dominguez @hallo_w3lt
 */

#include "PuzzleGrid.h"

#include "Helper.h"
#include "Behaviour/HowdyGameMode.h"
#include "Camera/CameraActor.h"
#include "Engine/TargetPoint.h"
#include "Kismet/GameplayStatics.h"

#define LOCTEXT_NAMESPACE "PuzzleGrid"

APuzzleGrid::APuzzleGrid(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = false;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	RootComponent = SceneComponent;
}

void APuzzleGrid::BeginPlay()
{
	Super::BeginPlay();

	if (nullptr != GetWorld())
	{
		HowdyGameMode = GetWorld()->GetAuthGameMode<AHowdyGameMode>();
	}

	if (nullptr == HowdyGameMode) { return; }

	Size = HowdyGameMode->GetSize();
	BlockSpacing = HowdyGameMode->GetBlockSpacing();

	FTransform Trans = {};
	ACameraActor* CameraActor{nullptr};
	TArray<AActor*> Actors = {};

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetPoint::StaticClass(), Actors);
	for (AActor* Target : Actors)
	{
		if (Cast<ATargetPoint>(Target))
		{
			if (Target->ActorHasTag(FName("TP_Grid")))
			{
				Trans = Target->GetActorTransform();
				Target->SetActorHiddenInGame(false);
			}
		}
	}

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), Actors);
	for (AActor* Camera : Actors)
	{
		if (Cast<ACameraActor>(Camera))
		{
			if (Camera->ActorHasTag(FName("C_MainCamera")))
			{
				CameraActor = Cast<ACameraActor>(Camera);
			}
		}
	}

	const auto GenerateGrid = [&](const FTransform& InTrans, ACameraActor& InCameraActor, const bool bColor)
	{
		int32 U{0}, V{0};
		for (int32 BlockIndex{0}; BlockIndex < FHelper::GetSize(Size); ++BlockIndex)
		{
			int32 const Mod{BlockIndex % Size};
			float const XOffset{static_cast<float>(BlockIndex / Size) * BlockSpacing};
			float const YOffset{Mod * BlockSpacing};

			if (BlockIndex > 0 && 0 == Mod)
			{
				U++;
				V = 0;
			}

			FVector BlockLocation{FVector(XOffset, YOffset, 0.f) + InTrans.GetLocation()};

			FTransform BlockTrans{InTrans};
			BlockTrans.SetLocation(BlockLocation);
			BlockTrans.SetRotation(FQuat(FRotator(0, 0, 0)));

			APuzzleBlock* PuzzleBlock{
				GetWorld()->SpawnActorDeferred<APuzzleBlock>(HowdyGameMode->GetPuzzleBlockClass(), BlockTrans)
			};
			PuzzleBlock->SetMaterialParameter({U, V++, Size, bColor ? 1 : 0});

			if (bColor)
			{
				PuzzleBlock->SetCanDragging(true);
			}

			PuzzleBlock->SetOwningGrid(this);

			PuzzleBlock->SetCamera(&InCameraActor);
			PuzzleBlock->SetIndex(BlockIndex);
			PuzzleBlock->FinishSpawning(BlockTrans);

			if (bColor)
			{
				Blocks.Add(PuzzleBlock);
			}
		}
	};

	GenerateGrid(Trans, *CameraActor, true);
}

void APuzzleGrid::Tick(const float InDeltaTime)
{
	Super::Tick(InDeltaTime);
}

#undef LOCTEXT_NAMESPACE
