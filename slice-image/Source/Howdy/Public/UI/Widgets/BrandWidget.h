/*
 *  Developed by IT&feel CA
 *  Author: @itandfeel
 *  Designer: Thamesis Marrero @thamesis09
 *  Programmer: Victor Dominguez @hallo_w3lt
 */

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "BrandWidget.generated.h"

/**
 * Brand Widget
 */
UCLASS()
class HOWDY_API UBrandWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	explicit UBrandWidget(const FObjectInitializer& MovieSceneBlends);

	virtual ~UBrandWidget() override;

protected:
	virtual void NativeConstruct() override;

private:
	UPROPERTY()
	class AHowdyGameMode* HowdyGameMode{nullptr};

	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true, BindWidget))
	class UTextBlock* BrandText{nullptr};
};
