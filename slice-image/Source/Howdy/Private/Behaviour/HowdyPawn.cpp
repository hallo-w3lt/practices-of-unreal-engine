/*
 *  Developed by IT&feel CA
 *  Author: @itandfeel
 *  Designer: Thamesis Marrero @thamesis09
 *  Programmer: Victor Dominguez @hallo_w3lt
 */

#include "HowdyPawn.h"

#include "HowdyGameMode.h"
#include "HowdyGameState.h"
#include "HowdyPlayerController.h"

AHowdyPawn::AHowdyPawn()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AHowdyPawn::BeginPlay()
{
	Super::BeginPlay();

	if (nullptr != GetWorld()) { HowdyGameMode = GetWorld()->GetAuthGameMode<AHowdyGameMode>(); }
	if (nullptr != HowdyGameMode) { HowdyGameState = HowdyGameMode->GetGameState<AHowdyGameState>(); }
}

void AHowdyPawn::Tick(const float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AHowdyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}