#pragma once
#include "Skill.h"
#include "Unit.h"

class MoveSkill : public Skill
{
public:
	MoveSkill();

	void SwapPositions(std::shared_ptr<Unit> castingUnit, std::shared_ptr<Unit> targetUnit);
};

