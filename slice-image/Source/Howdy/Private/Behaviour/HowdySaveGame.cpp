/*
 *  Developed by IT&feel CA
 *  Author: @itandfeel
 *  Designer: Thamesis Marrero @thamesis09
 *  Programmer: Victor Dominguez @hallo_w3lt
 */

#include "HowdySaveGame.h"

UHowdySaveGame::UHowdySaveGame(const FObjectInitializer& ObjectInitializer) : USaveGame(ObjectInitializer)
{
	SaveSlotName = TEXT("HowdyySaveGameSlot");
	UserIndex = 0;
}

UHowdySaveGame::~UHowdySaveGame()
{
	// ...
}
