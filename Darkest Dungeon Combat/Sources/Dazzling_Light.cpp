#include "Dazzling_Light.h"

Dazzling_Light::Dazzling_Light()
{
	name = "Dazzling Light";

	dmgMod = -75;
	baseAcc = 90;
	critMod = 5; // updt ltr pls ty and dis is mov

	usablePositions.push_back(2);
	usablePositions.push_back(3);
	usablePositions.push_back(4);

	targetablePositions.push_back(1);
	targetablePositions.push_back(2);
	targetablePositions.push_back(3);

	stunEffect = true;
	stunBase = 100;
}
