/*
 *  Developed by IT&feel CA
 *  Author: @itandfeel
 *  Designer: Thamesis Marrero @thamesis09
 *  Programmer: Victor Dominguez @hallo_w3lt
 */

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"

#include "Sandbox.generated.h"

/**
 * Level Class
 */
UCLASS()
class HOWDY_API ASandbox : public ALevelScriptActor
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
};
