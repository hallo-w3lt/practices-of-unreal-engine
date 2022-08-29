/*
 *  Developed by IT&feel CA
 *  Author: @itandfeel
 *  Designer: Thamesis Marrero @thamesis09
 *  Programmer: Victor Dominguez @hallo_w3lt
 */

#include "BrandWidget.h"

#include "HowdyGameMode.h"
#include "TextBlock.h"
#include "UMGSequencePlayer.h"
#include "Helper.h"

UBrandWidget::UBrandWidget(const FObjectInitializer& MovieSceneBlends) : UUserWidget(MovieSceneBlends)
{
	// ...
}

UBrandWidget::~UBrandWidget()
{
	// ...
}

void UBrandWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (nullptr != GetWorld()) { HowdyGameMode = GetWorld()->GetAuthGameMode<AHowdyGameMode>(); }
	if (nullptr == BrandText) { return; }

	BrandText->SetText(FText::FromString(FHelper::LetterSpacing(BrandText->GetText().ToString(), 2)));
}
