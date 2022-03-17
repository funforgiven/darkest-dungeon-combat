#include "Crusader.h"
#include <iostream>
#include "Smite.h"
#include "Stunning_Blow.h"
#include "Holy_Lance.h"
#include "Bulwark_of_Faith.h"


Crusader::Crusader(std::string name) : Hero(name)
{
	maxHP = 33;
	dodge = 5;
	prot = 0;
	speed = 1;
	accMod = 0;
	baseCrit = 3;
	minDmg = 6;
	maxDmg = 12;
	deathBlowResist = 67;
	stunResist = 40;

	hp = maxHP;

	skills.push_back(std::make_shared<Smite>());
	skills.push_back(std::make_shared<Stunning_Blow>());
	skills.push_back(std::make_shared<Holy_Lance>());
	skills.push_back(std::make_shared<Bulwark_of_Faith>());
}