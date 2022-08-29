/*
 *  Developed by IT&feel CA
 *  Author: @itandfeel
 *  Designer: Thamesis Marrero @thamesis09
 *  Programmer: Victor Dominguez @hallo_w3lt
 */

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"

#include "GameHUD.generated.h"

/**
 * Game HUD
 */
UCLASS()
class HOWDY_API AGameHUD : public AHUD
{
	GENERATED_BODY()

public:
	explicit AGameHUD(const FObjectInitializer& ObjectInitializer);

	virtual ~AGameHUD() override;

protected:
	virtual void BeginPlay() override;

	static void ShowWidget(UUserWidget& InWidget);
	static void HideWidget(UUserWidget& InWidget);

private:
	UPROPERTY()
	class AHowdyGameState* HowdyGameState{nullptr};

	UPROPERTY()
	class AHowdyGameMode* HowdyGameMode{nullptr};

	UPROPERTY(Category = Widgets, EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class UGridWidget> GridWidgetClass;

	UPROPERTY()
	UGridWidget* GridWidget{nullptr};

public:
	FORCEINLINE TSubclassOf<UGridWidget> GetGridWidgetClass() const { return GridWidgetClass; }
	FORCEINLINE UGridWidget* GetGridWidget() const { return GridWidget; }
};
