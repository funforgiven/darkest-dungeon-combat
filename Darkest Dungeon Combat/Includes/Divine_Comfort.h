#pragma once
#include "UtilitySkill.h"
class Divine_Comfort : public UtilitySkill
{
public:
	Divine_Comfort();
	void OnCast(std::shared_ptr<Unit> target) override;

};

