#include <iostream>
#include <algorithm>
#include "Unit.h"
#include "Utility.h"
#include "AttackSkill.h"
#include "StunSkill.h"
#include "MoveSkill.h"
#include "UtilitySkill.h"

Unit::Unit(std::string name)
{
	this->name = name;
	isDead = false;
	isStunned = false;

	skills.push_back(std::make_shared<MoveSkill>());
}

void Unit::Attack(std::vector<std::shared_ptr<Unit>> targets)
{
	nextStrikeCrit = false;

	if (isStunned)
	{
		std::cout << "\x1B[33m" << name << "\033[0m is stunned and \x1B[31mcannot attack!\033[0m" << std::endl;
		isStunned = false;
		return; 
	}

	std::shared_ptr<Unit> defender;
	std::shared_ptr<Skill> baseSkill;

	std::random_shuffle(targets.begin(), targets.end(), Utility::GenerateRandomShuffle);

	for (int i = 0; i < targets.size(); i++)
	{
		baseSkill = PickSuitableSkill(targets[i]->pos, SkillType::Attack);
		if (baseSkill != nullptr)
		{
			defender = targets[i];
			break;
		}
	}

	std::shared_ptr<UtilitySkill> utilitySkill = std::dynamic_pointer_cast<UtilitySkill>(baseSkill);
	if (utilitySkill != nullptr)
	{
		utilitySkill->OnCast(defender);
		std::cout << "\x1B[33m" << name << "\033[0m has used \x1B[36m" << utilitySkill->GetSkillName() << "!\033[0m" << std::endl;
		return;
	}

	// No spell can be used
	if (baseSkill == nullptr)
	{
		int random = Utility::GenerateRandom(0, 100);

		if ((random <= 50 && pos != targets.size()) || pos == 1)
			this->nextState = State::WillForceMoveBack;
		else
			this->nextState = State::WillForceMoveFront;

		return;
	}

	AttackSkill skill = dynamic_cast<AttackSkill&>(*baseSkill);
	baseSkill->OnCast();

	int rawDamage = CalculateRawDamage(skill);
	bool shouldStun = CalculateStun(skill, baseSkill, defender);

	std::cout << "\x1B[33m" << name << "\033[0m is attacking to \x1B[33m" << defender->name << "\033[0m with " << skill.GetSkillName() << "!" << std::endl;
	if(nextStrikeCrit) std::cout << "\x1B[33m" << name << "\033[0m will deal \x1B[31mcritical damage!\033[0m" << std::endl;

	defender->OnBeingAttacked(rawDamage, accMod, std::make_shared<AttackSkill>(skill), shouldStun);

}

std::shared_ptr<Skill> Unit::PickSuitableSkill(int targetPos, SkillType type)
{

	std::vector<std::shared_ptr<Skill>> usableSkills;

	for (auto it = skills.begin(); it != skills.end(); ++it)
		if ((*it)->isInUsablePositions(pos) && (*it)->isInTargetablePositions(targetPos) && (*it)->GetIsUsable())
			usableSkills.push_back(*it);

	// pick a skill //
	if (usableSkills.size() == 0) return nullptr;

 	std::shared_ptr<Skill> usableSkill = usableSkills[Utility::GenerateRandom(0, usableSkills.size() - 1)];

	// pick skill end //
	return usableSkill;
}

void Unit::CalculateSpeed()
{
	calculatedSpeed = speed + Utility::GenerateRandom(1, 8);
}

void Unit::CalculateNextState()
{
	int random = Utility::GenerateRandom(0, 100);

	if (random <= 90)
		nextState = State::WillAttackOrUtility;
	else
		nextState = State::WillMove;
}

void Unit::SetupSkills(std::shared_ptr<Unit> owner)
{
	for (int i = 0; i < skills.size(); i++)
		skills[i]->SetOwner(owner);
}

std::vector<std::shared_ptr<Skill>> Unit::GetAllSkills()
{
	return skills;
}

std::shared_ptr<MoveSkill> Unit::GetMoveSkill()
{
	for (int i = 0; i < skills.size(); i++)
		if (std::dynamic_pointer_cast<MoveSkill>(skills[i]))
			return std::dynamic_pointer_cast<MoveSkill>(skills[i]);

	return nullptr;
}

int Unit::CalculateRawDamage(AttackSkill skill)
{
	int rawDamage = Utility::GenerateRandom(minDmg, maxDmg) * ((100 + skill.GetDmgMod()) / 100);

	int criticalChance = skill.GetCritMod() + baseCrit;
	if (Utility::GenerateRandom(0, 100) <= criticalChance)
	{
		rawDamage = maxDmg * ((100 + skill.GetDmgMod()) / 100) * 1.5;
		nextStrikeCrit = true;
	}

	return rawDamage;
}

bool Unit::CalculateStun(AttackSkill skill, std::shared_ptr<Skill> baseSkill, std::shared_ptr<Unit> defender)
{
	bool shouldStun = false;

	if (skill.GetStunEffect())
	{
		StunSkill stunSkill = dynamic_cast<StunSkill&>(*baseSkill);
		int stunChance = stunSkill.GetStunBase() - defender->stunResist + (nextStrikeCrit ? 20 : 0);

		if (Utility::GenerateRandom(0, 100) <= stunChance)
			shouldStun = true;
	}

	return shouldStun;
}

int Unit::GetCalculatedSpeed()
{
	return calculatedSpeed;
}

int Unit::GetPos()
{
	return pos;
}

State Unit::GetState()
{
	return nextState;
}

bool Unit::GetIsDead()
{
	return isDead;
}

std::string Unit::GetName()
{
	return name;
}

Team Unit::GetTeam()
{
	return team;
}

void Unit::ChangeProt(int amount)
{
	prot += amount;
}

void Unit::ChangeHealth(int amount)
{
	hp += amount;
	if (hp > maxHP) hp = maxHP;
}

void Unit::ChangePos(int place)
{
	pos = place;
}

void Unit::ChangeNextState(State state)
{
	nextState = state;
}
