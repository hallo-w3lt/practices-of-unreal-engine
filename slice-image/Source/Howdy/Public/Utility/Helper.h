/*
 *  Developed by IT&feel CA
 *  Author: @itandfeel
 *  Designer: Thamesis Marrero @thamesis09
 *  Programmer: Victor Dominguez @hallo_w3lt
 */

#pragma once

#include "CoreMinimal.h"

/**
 * Helper Class
 */
class HOWDY_API FHelper
{
public:
	explicit FHelper() = default;
	~FHelper() = default;

	static TArray<int32> FillIntVector(const int32 InMax, const bool bReverse);
	static TArray<int32> RandomIntVector(int32 const InSize, int32 const InMin, int32 const InMax, bool bUnique = true);

	static int32 GetSize(int32 const InSize, bool const bExponential = true)
	{
		return bExponential ? InSize * InSize : InSize;
	}

	static FString LetterSpacing(FString const& InSource, int32 const InSpaces = 1);
};
