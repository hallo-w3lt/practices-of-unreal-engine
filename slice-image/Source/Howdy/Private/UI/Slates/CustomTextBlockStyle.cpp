/*
 *  Developed by IT&feel CA
 *  Author: @itandfeel
 *  Designer: Thamesis Marrero @thamesis09
 *  Programmer: Victor Dominguez @hallo_w3lt
 */

#include "Slates/CustomTextBlockStyle.h"

#define LOCTEXT_NAMESPACE "UMG"

UCustomTextBlockStyle::UCustomTextBlockStyle()
{
	static ConstructorHelpers::FObjectFinderOptional<USlateWidgetStyleAsset> CustomStyle(
		TEXT("SlateWidgetStyleAsset'/Game/UI/Styles/BP_CustonTextBlockStyle.BP_CustonTextBlockStyle'"));

	if (CustomStyle.Succeeded())
	{
		STextBlock::FArguments TextBlockDefaults;
		TextBlockDefaults.TextStyle(CustomStyle.Get());
	}
}

#if WITH_EDITOR
const FText UCustomTextBlockStyle::GetPaletteCategory()
{
	return LOCTEXT("", "Custom TextBlock");
}
#endif

#undef LOCTEXT_NAMESPACE
