#include "Axeblade.h"

Axeblade::Axeblade()
{
	name = "Axeblade";

	dmgMod = 0;
	baseAcc = 72;
	critMod = 6;

	usablePositions.push_back(1);
	usablePositions.push_back(2);

	targetablePositions.push_back(1);
	targetablePositions.push_back(2);

	stunEffect = false;
}
