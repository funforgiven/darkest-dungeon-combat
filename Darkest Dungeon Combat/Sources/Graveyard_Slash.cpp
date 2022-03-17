#include "Graveyard_Slash.h"

Graveyard_Slash::Graveyard_Slash()
{
	name = "Graveyard Slash";

	dmgMod = 0;
	baseAcc = 85;
	critMod = 6;

	usablePositions.push_back(1);
	usablePositions.push_back(2);
	usablePositions.push_back(3);

	targetablePositions.push_back(1);
	targetablePositions.push_back(2);
	targetablePositions.push_back(3);

	stunEffect = false;
}
