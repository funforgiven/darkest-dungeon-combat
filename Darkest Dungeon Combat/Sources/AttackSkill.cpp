#include "AttackSkill.h"
#include "Unit.h"
#include "Utility.h"

AttackSkill::AttackSkill()
{
	type = SkillType::Attack;
}

void AttackSkill::OnCast(std::shared_ptr<Unit> target)
{
}

void AttackSkill::OnCast()
{
}

int AttackSkill::GetDmgMod()
{
	return dmgMod;
}

int AttackSkill::GetBaseAcc()
{
	return baseAcc;
}

int AttackSkill::GetCritMod()
{
	return critMod;
}

bool AttackSkill::GetStunEffect()
{
	return stunEffect;
}
