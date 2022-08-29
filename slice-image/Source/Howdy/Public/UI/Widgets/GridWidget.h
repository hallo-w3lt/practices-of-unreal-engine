/*
 *  Developed by IT&feel CA
 *  Author: @itandfeel
 *  Designer: Thamesis Marrero @thamesis09
 *  Programmer: Victor Dominguez @hallo_w3lt
 */

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "GridWidget.generated.h"

/**
 * Grid Widget
 */
UCLASS()
class HOWDY_API UGridWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	explicit UGridWidget(const FObjectInitializer& MovieSceneBlends);
	virtual ~UGridWidget() override;

protected:
	virtual void NativeConstruct() override;

private:
	UPROPERTY(Category = Widgets, BlueprintReadWrite, meta = (AllowPrivateAccess = true, BindWidget))
	class UBrandWidget* BrandWidget{nullptr};

public:
	FORCEINLINE class UBrandWidget* GetScoreWidget() const { return BrandWidget; }
};
