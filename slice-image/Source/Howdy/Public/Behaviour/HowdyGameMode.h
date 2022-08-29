/*
 *  Developed by IT&feel CA
 *  Author: @itandfeel
 *  Designer: Thamesis Marrero @thamesis09
 *  Programmer: Victor Dominguez @hallo_w3lt
 */

#pragma once

#include "CoreMinimal.h"
#include "PuzzleBlock.h"
#include "GameFramework/GameModeBase.h"

#include "HowdyGameMode.generated.h"

/**
 * GameMode Base Class
 */
UCLASS()
class HOWDY_API AHowdyGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	explicit AHowdyGameMode(const FObjectInitializer& ObjectInitializer);

	virtual ~AHowdyGameMode() override;

	virtual void InitGameState() override;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float InDeltaSeconds) override;

private:
	UPROPERTY(Category = Class, EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<APuzzleBlock> PuzzleBlockClass;

	UPROPERTY()
	AHowdyPlayerController* PlayerController{nullptr};

	UPROPERTY(Category = Grid, EditAnywhere, BlueprintReadOnly, meta = (UIMin = 3, UIMax = 4, AllowPrivateAccess = "true"))
	int32 Size{4};

	UPROPERTY(Category = Grid, EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float BlockSpacing{110.f};

public:
	FORCEINLINE TSubclassOf<APuzzleBlock> GetPuzzleBlockClass() const { return PuzzleBlockClass; }
	FORCEINLINE int32 GetSize() const { return Size; }
	FORCEINLINE int32 GetBlockSpacing() const { return BlockSpacing; }
};
