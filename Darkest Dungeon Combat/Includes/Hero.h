#pragma once

#include "Unit.h"

class Hero : public Unit
{
protected:

	int deathBlowResist;

public:

	Hero(std::string name);
	
	void OnBeingAttacked(int amount, int accMod, std::shared_ptr<AttackSkill> skill, bool shouldStun) override;
};