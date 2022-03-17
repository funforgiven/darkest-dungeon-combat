#include "Skill.h"
#include <iostream>

Skill::Skill()
{
	isUsable = true;
}

void Skill::OnCast(std::shared_ptr<Unit> target)
{
	//std::cout << "Skill not implemented!" << std::endl;
}

void Skill::OnCast()
{
	//std::cout << "Skill not implemented!" << std::endl;
}

void Skill::OnEffectWornOut()
{
}

std::string Skill::GetSkillName()
{
	return name;
}

SkillType Skill::GetSkillType()
{
	return type;
}

void Skill::SetOwner(std::shared_ptr<Unit> owner)
{
	this->owner = owner;
}

bool Skill::isInUsablePositions(int pos)
{
	bool result = false;

	for (auto it = usablePositions.begin(); it != usablePositions.end(); ++it)
		if (*it == pos)
			result = true;

	return result;
}

bool Skill::isInTargetablePositions(int pos)
{
	bool result = false;

	for (auto it = targetablePositions.begin(); it != targetablePositions.end(); ++it)
		if (*it == pos)
			result = true;

	return result;
}

void Skill::SkillTick()
{
	effectDuration--;
	
	if (effectDuration == 0)
		this->OnEffectWornOut();

}

bool Skill::GetIsUsable()
{
	return isUsable;
}
