#include <random>
#include <chrono>
#include "Utility.h"

static unsigned long long randomizer = 0;

int Utility::GenerateRandom(int lowerLimit, int upperLimit)
{
	srand(time(NULL) + randomizer);

	int random = lowerLimit + (rand() % (upperLimit - lowerLimit + 1));

	randomizer++;
	return random;
}

int Utility::GenerateRandomShuffle(int i)
{
	srand(time(NULL) + randomizer);

	int random = rand() % i;

	randomizer++;
	return random;
}

bool Utility::CompareUnitSpeeds(std::shared_ptr<Unit> unit1, std::shared_ptr<Unit> unit2)
{
	return unit1->GetCalculatedSpeed() < unit2->GetCalculatedSpeed();
}


