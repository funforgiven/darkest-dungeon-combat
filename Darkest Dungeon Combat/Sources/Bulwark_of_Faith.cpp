#include "Bulwark_of_Faith.h"
#include "Unit.h"
#include <iostream>
Bulwark_of_Faith::Bulwark_of_Faith()
{

	name = "Bulwark of Faith";

	usablePositions.push_back(1);
	usablePositions.push_back(2);

	targetablePositions.push_back(1);
	targetablePositions.push_back(2);
	targetablePositions.push_back(3);
	targetablePositions.push_back(4);
}

void Bulwark_of_Faith::OnCast(std::shared_ptr<Unit> target)
{
	effectDuration = 3;
	isUsable = false;
	owner->ChangeProt(20);
}

void Bulwark_of_Faith::OnEffectWornOut()
{
	owner->ChangeProt(-20);
	isUsable = true;
	std::cout << "Effect of " << name << " worn out on " << owner->GetName() << "!" << std::endl;
}
