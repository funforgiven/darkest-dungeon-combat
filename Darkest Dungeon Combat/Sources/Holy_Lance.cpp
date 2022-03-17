#include "Holy_Lance.h"
#include "MoveSkill.h"
#include <iostream>

Holy_Lance::Holy_Lance()
{
	name = "Holy Lance";

	dmgMod = 0;
	baseAcc = 85;
	critMod = 6.5;
	
	usablePositions.push_back(3);
	usablePositions.push_back(4);

	targetablePositions.push_back(2);
	targetablePositions.push_back(3);
	targetablePositions.push_back(4);

	stunEffect = false;
}

void Holy_Lance::OnCast()
{
	owner->ChangeNextState(State::WillForceMoveFront);
}
