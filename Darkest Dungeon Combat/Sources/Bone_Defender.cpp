#include "Bone_Defender.h"
#include "Axeblade.h"
#include "Dead_Weight.h"
#include "Knitting_Bones.h"

Bone_Defender::Bone_Defender(std::string name) : Monster(name)
{
	maxHP = 22;
	dodge = 8;
	prot = 45;
	speed = 1;
	accMod = 0;
	baseCrit = 0;
	minDmg = 2;
	maxDmg = 4;
	stunResist = 45;

	hp = maxHP;

	skills.push_back(std::make_shared<Axeblade>());
	skills.push_back(std::make_shared<Dead_Weight>());
	skills.push_back(std::make_shared<Knitting_Bones>());
}