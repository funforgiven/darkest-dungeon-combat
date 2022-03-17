#include "Smite.h"
#include "..\Includes\Smite.h"

Smite::Smite()
{
	name = "Smite";

	usablePositions.push_back(1);
	usablePositions.push_back(2);

	targetablePositions.push_back(1);
	targetablePositions.push_back(2);

	dmgMod = 0;
	baseAcc = 85;
	critMod = 0;

	stunEffect = false;

}
