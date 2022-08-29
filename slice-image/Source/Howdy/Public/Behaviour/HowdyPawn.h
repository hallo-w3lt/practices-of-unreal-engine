/*
 *  Developed by IT&feel CA
 *  Author: @itandfeel
 *  Designer: Thamesis Marrero @thamesis09
 *  Programmer: Victor Dominguez @hallo_w3lt
 */

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "HowdyPawn.generated.h"

UCLASS()
class HOWDY_API AHowdyPawn : public APawn
{
	GENERATED_BODY()

public:
	explicit AHowdyPawn();

	virtual ~AHowdyPawn() override;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float InDeltaTime) override;

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY()
	class AHowdyGameMode* HowdyGameMode{nullptr};

	UPROPERTY()
	class AHowdyGameState* HowdyGameState{nullptr};
};
