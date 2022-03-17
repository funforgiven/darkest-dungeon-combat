#pragma once
#include <vector>
#include <memory>
#include <string>

class Unit;

enum class SkillType
{
	Attack,
	Utility,
	Move
};

class Skill
{
protected:
	std::vector<int> usablePositions;
	std::vector<int> targetablePositions;

	std::shared_ptr<Unit> owner;
	std::string name;

	SkillType type;
	int effectDuration;

	bool isUsable;

public:
	Skill();

	virtual void OnCast(std::shared_ptr<Unit> target);
	virtual void OnCast();
	virtual void OnEffectWornOut();

	std::string GetSkillName();
	SkillType GetSkillType();
	void SetOwner(std::shared_ptr<Unit> owner);

	bool isInUsablePositions(int pos);
	bool isInTargetablePositions(int pos);
	void SkillTick();

	bool GetIsUsable();

};

