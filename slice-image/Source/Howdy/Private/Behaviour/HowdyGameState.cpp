/*
 *  Developed by IT&feel CA
 *  Author: @itandfeel
 *  Designer: Thamesis Marrero @thamesis09
 *  Programmer: Victor Dominguez @hallo_w3lt
 */

#include "HowdyGameState.h"

#include "HowdyGameMode.h"
#include "HowdyPlayerController.h"
#include "HowdyTypes.h"

AHowdyGameState::AHowdyGameState(const FObjectInitializer& ObjectInitializer) : AGameStateBase(ObjectInitializer)
{
	// ...
}

AHowdyGameState::~AHowdyGameState()
{
	// ...
}

void AHowdyGameState::BeginPlay()
{
	Super::BeginPlay();

	PlayerController = Cast<AHowdyPlayerController>(GetWorld()->GetFirstPlayerController());
}

void AHowdyGameState::OnGameStart()
{
	SetGameplayState(EGameplayStateType::Playing);
}

void AHowdyGameState::StartGameplayStateMachine()
{
	HowdyGameMode = Cast<AHowdyGameMode>(GetDefaultGameMode());

	OnGameStart();
}

void AHowdyGameState::SetGameplayState(EGameplayStateType const InState)
{
	GameplayState = InState;
}

void AHowdyGameState::FinishGame()
{
	if (nullptr == PlayerController) { return; }

	GetWorldTimerManager().ClearAllTimersForObject(this);
	SetGameplayState(EGameplayStateType::Finished);
	PlayerController->SetInputMode(FInputModeGameOnly());
	GameplayState = EGameplayStateType::Finished;
}
