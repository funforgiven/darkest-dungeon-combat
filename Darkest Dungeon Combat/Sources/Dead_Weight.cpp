#include "Dead_Weight.h"

Dead_Weight::Dead_Weight()
{
	name = "Dead Weight";

	dmgMod = -25;
	baseAcc = 82;
	critMod = 6;

	usablePositions.push_back(1);
	usablePositions.push_back(2);
	usablePositions.push_back(3);

	targetablePositions.push_back(1);
	targetablePositions.push_back(2);

	stunEffect = true;
	stunBase = 100;
}
