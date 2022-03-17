#pragma once
#include "Skill.h"

class UtilitySkill : public Skill
{
public:
	UtilitySkill();
	void OnCast(std::shared_ptr<Unit> target) override;

};

