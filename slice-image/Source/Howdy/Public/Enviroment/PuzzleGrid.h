/*
 *  Developed by IT&feel CA
 *  Author: @itandfeel
 *  Designer: Thamesis Marrero @thamesis09
 *  Programmer: Victor Dominguez @hallo_w3lt
 */

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "PuzzleGrid.generated.h"

UCLASS()
class HOWDY_API APuzzleGrid : public AActor
{
	GENERATED_BODY()

public:
	explicit APuzzleGrid(const FObjectInitializer& ObjectInitializer);

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(Category = Grid, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	USceneComponent* SceneComponent{nullptr};

	UPROPERTY(Category = Grid, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class ATargetPoint* TargetPoint{nullptr};

	UPROPERTY()
	class AHowdyGameMode* HowdyGameMode{nullptr};

	int32 Size{0};
	float BlockSpacing{0.f};

	TArray<class APuzzleBlock*> Blocks = {};
	int32 OverlappedBlocks{0};

public:
	FORCEINLINE USceneComponent* GetMainComponent() const { return SceneComponent; }
	FORCEINLINE int32 IncrementOverlappedBlocks() { return ++OverlappedBlocks; }

	FORCEINLINE int32 GetSize() const { return Size; }
	FORCEINLINE int32 GetBlockSpacing() const { return BlockSpacing; }
};
