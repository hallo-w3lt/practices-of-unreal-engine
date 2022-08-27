/*
 *  Developed by IT&feel CA
 *  Author: @itandfeel
 *  Designer: Thamesis Marrero @thamesis09
 *  Programmer: Victor Dominguez @hallo_w3lt
 */

#pragma once

#include "CoreMinimal.h"
#include "HowdyTypes.h"
#include "GameFramework/GameState.h"

#include "HowdyGameState.generated.h"


/**
 * GameState Class
 */
UCLASS(Config = Game)
class HOWDY_API AHowdyGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	explicit AHowdyGameState(const FObjectInitializer& ObjectInitializer);
	virtual ~AHowdyGameState() {};

protected:
	virtual void BeginPlay() override;

public:
	void OnGameStart();

	UFUNCTION(BlueprintCallable, Category = Game)
		void FinishGame();

	void StartGameplayStateMachine();

	void SetGameplayState(EGameplayState::Type InState);

private:
	UPROPERTY()
		class AHowdyPlayerController* PlayerController{ nullptr };
	UPROPERTY()
		const class AHowdyGameMode* HowdyGameMode{ nullptr };

	EGameplayState::Type GameplayState;

public:
	FORCEINLINE bool IsGameFinished() const { return EGameplayState::Finished == GameplayState; }
	FORCEINLINE bool IsGamePaying() const { return EGameplayState::Playing == GameplayState; }
	FORCEINLINE int32 GetGameStat() const { return GameplayState; }
};
