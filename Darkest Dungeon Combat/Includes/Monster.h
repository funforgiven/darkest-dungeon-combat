#pragma once

#include "Unit.h"

class Monster : public Unit
{
public:
	Monster(std::string name);

	void OnBeingAttacked(int amount, int accMod, std::shared_ptr<AttackSkill> skill, bool shouldStun) override;

};

