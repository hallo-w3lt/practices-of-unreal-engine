/*
 *  Developed by IT&feel CA
 *  Author: @itandfeel
 *  Designer: Thamesis Marrero @thamesis09
 *  Programmer: Victor Dominguez @hallo_w3lt
 */

#include "HowdyPlayerController.h"

AHowdyPlayerController::AHowdyPlayerController(const FObjectInitializer& ObjectInitializer): Super(ObjectInitializer)
{
	bShowMouseCursor = true;
	bEnableClickEvents = true;
	bEnableTouchEvents = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}

APlayerController* AHowdyPlayerController::GetPlayerController() const
{
	return GetWorld()->GetFirstPlayerController();
}
