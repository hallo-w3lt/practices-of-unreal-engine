/*
 *  Developed by IT&feel CA
 *  Author: @itandfeel
 *  Designer: Thamesis Marrero @thamesis09
 *  Programmer: Victor Dominguez @hallo_w3lt
 */

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"

#include "HowdySaveGame.generated.h"

/**
 * SaveGame
 */
UCLASS()
class HOWDY_API UHowdySaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	explicit UHowdySaveGame(const FObjectInitializer& ObjectInitializer);
	~UHowdySaveGame() {};

private:
	FString SaveSlotName {};
	uint32 UserIndex{0};

	UPROPERTY(Category = Basic, VisibleAnywhere)
		bool bSound{ true };

	UPROPERTY(Category = Basic, VisibleAnywhere)
		float MusicVolume{ 0.3f };

	UPROPERTY(Category = Basic, VisibleAnywhere)
		int32 MaxScore{ 0 };

	UPROPERTY(Category = Basic, VisibleAnywhere)
		int32 Deaths{ 0 };

public:
	FORCEINLINE FString GetSaveSlotName() const { return SaveSlotName; }
	FORCEINLINE uint32 GetUSerIndex() const { return UserIndex; }
};
