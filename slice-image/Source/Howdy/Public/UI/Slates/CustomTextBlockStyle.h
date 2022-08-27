/*
 *  Developed by IT&feel CA
 *  Author: @itandfeel
 *  Designer: Thamesis Marrero @thamesis09
 *  Programmer: Victor Dominguez @hallo_w3lt
 */

#pragma once

#include "CoreMinimal.h"
#include "TextBlock.h"

#include "CustomTextBlockStyle.generated.h"

/**
 * Custom TexBlock Class
 */
UCLASS(meta = (DisplayName = "TextBlock Style"))
class HOWDY_API UCustomTextBlockStyle : public UTextBlock
{
	GENERATED_BODY()

public:
	UCustomTextBlockStyle();

#if WITH_EDITOR
	virtual const FText GetPaletteCategory() override;
#endif
};
