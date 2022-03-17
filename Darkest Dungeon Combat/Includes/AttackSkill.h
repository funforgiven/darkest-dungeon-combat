#pragma once
#include "Skill.h"
class AttackSkill : public Skill
{
protected:
	int dmgMod;
	int baseAcc;
	double critMod;
	
	bool stunEffect;

public:
	AttackSkill();

	void OnCast(std::shared_ptr<Unit> target);
	void OnCast();

	int GetDmgMod();
	int GetBaseAcc();
	int GetCritMod();
	bool GetStunEffect();

};

