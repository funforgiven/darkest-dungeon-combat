#include "Bone_Soldier.h"
#include "Graveyard_Slash.h"
#include "Graveyard_Stumble.h"

Bone_Soldier::Bone_Soldier(std::string name) : Monster(name)
{
	maxHP = 10;
	dodge = 10;
	prot = 15;
	speed = 4;
	accMod = 0;
	baseCrit = 0;
	minDmg = 3;
	maxDmg = 8;
	stunResist = 25;

	hp = maxHP;

	skills.push_back(std::make_shared<Graveyard_Slash>());
	skills.push_back(std::make_shared<Graveyard_Stumble>());

}
