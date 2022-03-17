#pragma once
#include "UtilitySkill.h"
class Divine_Grace : public UtilitySkill
{
public:
	Divine_Grace();
	void OnCast(std::shared_ptr<Unit> target) override;

};

