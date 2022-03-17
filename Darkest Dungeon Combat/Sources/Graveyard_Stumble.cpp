#include "Graveyard_Stumble.h"
#include "MoveSkill.h"

Graveyard_Stumble::Graveyard_Stumble()
{
	name = "Graveyard Stumble";

	dmgMod = -50;
	baseAcc = 45;
	critMod = 0;

	usablePositions.push_back(4);

	targetablePositions.push_back(1);
	targetablePositions.push_back(2);

	stunEffect = false;
}

void Graveyard_Stumble::OnCast()
{
	owner->ChangeNextState(State::WillForceMoveFront);
}
