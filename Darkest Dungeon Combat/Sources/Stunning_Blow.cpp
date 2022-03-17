#include "Stunning_Blow.h"

Stunning_Blow::Stunning_Blow()
{
	name = "Stunning Blow";
	dmgMod = -50;
	baseAcc = 90;
	critMod = 0;
	stunEffect = true;

	usablePositions.push_back(1);
	usablePositions.push_back(2);

	targetablePositions.push_back(1);
	targetablePositions.push_back(2);

	stunBase = 100;	
}
