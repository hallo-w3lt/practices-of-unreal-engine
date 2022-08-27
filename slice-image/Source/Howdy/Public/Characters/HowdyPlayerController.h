/*
 *  Developed by IT&feel CA
 *  Author: @itandfeel
 *  Designer: Thamesis Marrero @thamesis09
 *  Programmer: Victor Dominguez @hallo_w3lt
 */

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "HowdyPlayerController.generated.h"

/**
 * PlayerController CLass
 */
UCLASS()
class HOWDY_API AHowdyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	explicit AHowdyPlayerController(const FObjectInitializer& ObjectInitializer);

	APlayerController* GetPlayerController() const;
};
