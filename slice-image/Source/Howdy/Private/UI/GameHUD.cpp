/*
 *  Developed by IT&feel CA
 *  Author: @itandfeel
 *  Designer: Thamesis Marrero @thamesis09
 *  Programmer: Victor Dominguez @hallo_w3lt
 */

#include "GameHUD.h"

#include "HowdyGameMode.h"
#include "HowdyGameState.h"
#include "GridWidget.h"

AGameHUD::AGameHUD(const FObjectInitializer& ObjectInitializer) : AHUD(ObjectInitializer)
{
	// ...
}

void AGameHUD::BeginPlay()
{
	Super::BeginPlay();

	if (nullptr == GridWidgetClass) { return; }

	if (nullptr != GetWorld()) { HowdyGameMode = GetWorld()->GetAuthGameMode<AHowdyGameMode>(); }
	if (nullptr != HowdyGameMode) { HowdyGameState = HowdyGameMode->GetGameState<AHowdyGameState>(); }
	if (nullptr == HowdyGameState) { return; }

	GridWidget = CreateWidget<UGridWidget>(GetWorld(), GridWidgetClass);
	if (nullptr == GridWidget) { return; }

	ShowWidget(*GridWidget);
}

void AGameHUD::ShowWidget(UUserWidget& InWidget) const
{
	InWidget.AddToViewport();
}

void AGameHUD::HideWidget(UUserWidget& InWidget) const
{
	InWidget.RemoveFromParent();
}
