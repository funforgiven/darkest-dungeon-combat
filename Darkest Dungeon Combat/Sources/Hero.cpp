#include "Hero.h"
#include "Utility.h"
#include <iostream>

Hero::Hero(std::string name) : Unit(name)
{
	team = Team::Heroes;
}

void Hero::OnBeingAttacked(int amount, int accMod, std::shared_ptr<AttackSkill> skill, bool shouldStun)
{

	if (hp <= 0)
	{
		if (Utility::GenerateRandom(0, 100) > deathBlowResist)
		{
			isDead = true;
			std::cout << "\x1B[31m" << name << " has died!\033[0m" << std::endl;
		}
		else {
			if (shouldStun)
			{
				isStunned = true;
				std::cout << "\x1B[33m" << name << "\033[0m has been \x1B[31mstunned!\033[0m" << std::endl;
			}
		}
	}
	else {

		int hitChance = accMod - dodge + skill->GetBaseAcc(); // + Base accurracy of the skill
		int actualDamage = amount - (prot / 100);

		if (Utility::GenerateRandom(0, 100) <= hitChance)
		{
			std::cout << "\x1B[33m" << name << "\033[0m took \x1B[35m" << actualDamage << " damage\033[0m!" << std::endl;
			hp -= actualDamage;

			if (shouldStun)
			{
				isStunned = true;
				std::cout << name << " has been stunned!" << std::endl;
			}
		}
		else
		{
			std::cout << "\x1B[33m" << name << "\033[0m dodged the attack!" << std::endl;
		}

		if (hp <= 0)
		{
			std::cout << "\x1B[31m" << name << " is now on Death's door!\033[0m" << std::endl;
		}
	}
}
