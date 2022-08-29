/*
 *  Developed by IT&feel CA
 *  Author: @itandfeel
 *  Designer: Thamesis Marrero @thamesis09
 *  Programmer: Victor Dominguez @hallo_w3lt
 */

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"

#include "HowdyGameInstance.generated.h"

/**
 * GameInstance Class
 */
UCLASS()
class HOWDY_API UHowdyGameInstance : public UGameInstance
{
	GENERATED_BODY()

private:
	bool bIsNewRecord{false};
	bool bIsApproachingNewRecord{false};
	bool bSound{true};
	float ScaleMusicVolume{0.3f};
	float ScaleFXVolume{0.3f};

	// void Save();
	// void Load();

public:
	FORCEINLINE bool IsApproachingNewRecord() const { return bIsApproachingNewRecord; }
	FORCEINLINE bool IsNewRecord() const { return bIsNewRecord; }
};
