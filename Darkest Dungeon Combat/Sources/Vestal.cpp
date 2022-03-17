#include "Vestal.h"
#include <iostream>

#include "Mace_Bash.h"
#include "Dazzling_Light.h"
#include "Divine_Grace.h"
#include "Divine_Comfort.h"

Vestal::Vestal(std::string name) : Hero(name)
{
	maxHP = 24;
	dodge = 0;
	prot = 0;
	speed = 4;
	accMod = 0;
	baseCrit = 1;
	minDmg = 4;
	maxDmg = 8;
	deathBlowResist = 77;
	stunResist = 30;

	hp = maxHP;

	skills.push_back(std::make_shared<Dazzling_Light>());
	skills.push_back(std::make_shared<Mace_Bash>());
	skills.push_back(std::make_shared<Divine_Grace>());
	skills.push_back(std::make_shared<Divine_Comfort>());

}