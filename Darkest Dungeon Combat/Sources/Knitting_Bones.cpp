#include "Knitting_Bones.h"
#include "Utility.h"
#include <iostream>

Knitting_Bones::Knitting_Bones()
{
	name = "Knitting Bones";

	usablePositions.push_back(3);
	usablePositions.push_back(4);

	targetablePositions.push_back(1);
	targetablePositions.push_back(2);
	targetablePositions.push_back(3);
	targetablePositions.push_back(4);
}

void Knitting_Bones::OnCast(std::shared_ptr<Unit> target)
{
	int healAmount = Utility::GenerateRandom(2, 3);

	std::vector<std::shared_ptr<Unit>> livingUnits;
	std::vector<std::shared_ptr<Unit>> allyUnits = owner->allies;

	for (int i = 0; i < allyUnits.size(); i++)
		if (!allyUnits[i]->GetIsDead()) livingUnits.push_back(allyUnits[i]);

	std::shared_ptr<Unit> selectedUnit = livingUnits[Utility::GenerateRandom(0, livingUnits.size() - 1)];
	selectedUnit->ChangeHealth(healAmount);

	std::cout << owner->GetName() << " has healed " << selectedUnit->GetName() << " by " << healAmount << "!" << std::endl;
}
