#pragma once
#include "UtilitySkill.h"
class Knitting_Bones : public UtilitySkill
{
public:
	Knitting_Bones();
	void OnCast(std::shared_ptr<Unit> target) override;
};

