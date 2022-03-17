#include "Divine_Comfort.h"
#include "Utility.h"
#include <iostream>

Divine_Comfort::Divine_Comfort()
{
	name = "Divine Comfort";

	usablePositions.push_back(2);
	usablePositions.push_back(3);
	usablePositions.push_back(4);

	targetablePositions.push_back(1);
	targetablePositions.push_back(2);
	targetablePositions.push_back(3);
	targetablePositions.push_back(4);
}

void Divine_Comfort::OnCast(std::shared_ptr<Unit> target)
{
	int healAmount = Utility::GenerateRandom(1, 3);

	std::vector<std::shared_ptr<Unit>> livingUnits;
	std::vector<std::shared_ptr<Unit>> allyUnits = owner->allies;

	for (int i = 0; i < allyUnits.size(); i++)
		if (!allyUnits[i]->GetIsDead()) livingUnits.push_back(allyUnits[i]);

	for (int i = 0; i < livingUnits.size(); i++)
	{
		livingUnits[i]->ChangeHealth(healAmount);

	}

	std::cout << owner->GetName() << " has healed all allies by " << healAmount << "!" << std::endl;
}
