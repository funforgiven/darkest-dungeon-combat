#include "Monster.h"
#include "Utility.h"
#include <iostream>

Monster::Monster(std::string name) : Unit(name)
{
	team = Team::Monsters;
}

void Monster::OnBeingAttacked(int amount, int accMod, std::shared_ptr<AttackSkill> skill, bool shouldStun)
{
	int hitChance = accMod - dodge + skill->GetBaseAcc(); // + Base accurracy of the skill
	int actualDamage = amount - (prot / 100);

	if (Utility::GenerateRandom(0, 100) <= hitChance)
	{
		hp -= actualDamage;
		std::cout << "\x1B[33m" << name << "\033[0m took \x1B[35m" << actualDamage << " damage\033[0m!" << std::endl;
		if (shouldStun)
		{
			isStunned = true;
			std::cout << "\x1B[33m" << name << "\033[0m has been \x1B[31mstunned!\033[0m" << std::endl;
		}
	}
	else
	{
		std::cout << "\x1B[33m" << name << "\033[0m dodged the attack" << std::endl;
	}

	if (hp <= 0)
	{
		isDead = true;
		std::cout << "\x1B[31m" << name << " has died!\033[0m" << std::endl;
	}
}
