/*
 *  Developed by IT&feel CA
 *  Author: @itandfeel
 *  Designer: Thamesis Marrero @thamesis09
 *  Programmer: Victor Dominguez @hallo_w3lt
 */


#include "HowdyGameMode.h"

#include "HowdyGameState.h"
#include "HowdyPawn.h"
#include "HowdyPlayerController.h"
#include "UserWidget.h"
#include "Kismet/GameplayStatics.h"

AHowdyGameMode::AHowdyGameMode(const FObjectInitializer& ObjectInitializer) : AGameModeBase(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = false;
	DefaultPawnClass = AHowdyPawn::StaticClass();
	PlayerControllerClass = AHowdyPlayerController::StaticClass();
}

AHowdyGameMode::~AHowdyGameMode()
{
	// ...
}

void AHowdyGameMode::InitGameState()
{
	Super::InitGameState();

	auto* const HowdyGameState{GetGameState<AHowdyGameState>()};
	if (nullptr == HowdyGameState) { return; }

	HowdyGameState->StartGameplayStateMachine();
}

void AHowdyGameMode::BeginPlay()
{
	Super::BeginPlay();
}

void AHowdyGameMode::Tick(const float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}
