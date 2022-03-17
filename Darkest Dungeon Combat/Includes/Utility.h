#pragma once
#include <memory>
#include "Unit.h"

static class Utility
{
public:
	static int GenerateRandom(int lowerLimit, int upperLimit);
	static int GenerateRandomShuffle(int i);
	static bool CompareUnitSpeeds(std::shared_ptr<Unit> unit1, std::shared_ptr<Unit> unit2);
};

