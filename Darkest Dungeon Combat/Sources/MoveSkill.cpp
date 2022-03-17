#include "MoveSkill.h"
#include <iostream>

MoveSkill::MoveSkill()
{
}

void MoveSkill::SwapPositions(std::shared_ptr<Unit> casterUnit, std::shared_ptr<Unit> targetUnit)
{
	
	int casterPos = casterUnit->GetPos();
	int targetPos = targetUnit->GetPos();

	if(casterPos > targetPos)
		std::cout << "\x1B[33m" << casterUnit->GetName() << "\033[0m has moved 1 unit \x1B[34mfront!\033[0m" << std::endl;
	else
		std::cout << "\x1B[33m" << casterUnit->GetName() << "\033[0m has moved 1 unit \x1B[34mback!\033[0m" << std::endl;


	casterUnit->ChangePos(targetPos);
	targetUnit->ChangePos(casterPos);
}
