#pragma once
#include "AttackSkill.h"

class Graveyard_Stumble : public AttackSkill
{
public:
	Graveyard_Stumble();
	void OnCast() override;

};

