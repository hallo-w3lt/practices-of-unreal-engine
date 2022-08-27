/*
 *  Developed by IT&feel CA
 *  Author: @itandfeel
 *  Designer: Thamesis Marrero @thamesis09
 *  Programmer: Victor Dominguez @hallo_w3lt
 */

#include "Helper.h"
#include <Algo/Reverse.h>

TArray<int32> Helper::FillIntVector(const int32 InMin, const int32 InMax, const bool bReverse = false)
{
	TArray<int32> Buffer = {};
	Buffer.Reserve(InMax);

	for (int32 Counter{ 0 }; Counter < InMax; ++Counter)
	{
		Buffer.AddUnique(Counter);
	}

	if (bReverse) {
		Algo::Reverse(Buffer);
	}

	return Buffer;
}

TArray<int32> Helper::RandomIntVector(const int32 InSize, const int32 Min, const int32 Max, const bool bUnique)
{
	int64 const DateInSeconds{ FDateTime::Now().ToUnixTimestamp() };
	FRandomStream SRand{ FRandomStream() };
	SRand.Initialize(DateInSeconds);

	TArray<int32> Buffer = {};
	Buffer.Reserve(InSize);

	auto Counter{ 0 };
	do
	{
		if (bUnique)
		{
			Buffer.AddUnique(SRand.RandRange(Min, Max));
		}
		else
		{
			Buffer.Add(SRand.RandRange(Min, Max));
		}
	} while (++Counter < Max);

	return Buffer;
}

FString Helper::LetterSpacing(FString const& InSource, const int32 InSpaces)
{
	FString Buffer{};
	std::string const Spacing(InSpaces, ' ');
	for (auto const& Letter : InSource)
	{
		Buffer += Letter;
		Buffer += Spacing.c_str();
	}

	return Buffer;
}


