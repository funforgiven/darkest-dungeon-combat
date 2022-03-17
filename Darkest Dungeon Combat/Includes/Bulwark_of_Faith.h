#pragma once
#include "UtilitySkill.h"
class Bulwark_of_Faith : public UtilitySkill
{
public:
	Bulwark_of_Faith();
	void OnCast(std::shared_ptr<Unit> target) override;
	void OnEffectWornOut() override;
};

