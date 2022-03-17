#include "Mace_Bash.h"
#include "..\Includes\Mace_Bash.h"

Mace_Bash::Mace_Bash()
{
	name = "Mace Bash";

	dmgMod = 0;
	baseAcc = 85;
	critMod = 0;

	usablePositions.push_back(1);
	usablePositions.push_back(2);

	targetablePositions.push_back(1);
	targetablePositions.push_back(2);

	stunEffect = false;
}
