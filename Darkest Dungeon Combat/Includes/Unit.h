#pragma once
#include <memory>
#include <string>
#include <vector>
#include "AttackSkill.h"

class MoveSkill;

enum class State {
	WillAttackOrUtility,
	WillMove,
	WillForceMoveFront,
	WillForceMoveBack
};

enum class Team {
	Heroes,
	Monsters
};

class Unit
{

protected:

	std::string name;
	Team team;

	int maxHP;
	int dodge;
	int prot;
	int speed;
	int accMod;
	int baseCrit;
	int minDmg;
	int maxDmg;
	int stunResist;

	int hp;
	int calculatedSpeed;
	int pos;

	bool nextStrikeCrit;
	bool isDead;
	bool isStunned;

	State nextState;

	std::vector<std::shared_ptr<Skill>> skills;

	int CalculateRawDamage(AttackSkill skill);
	bool CalculateStun(AttackSkill skill, std::shared_ptr<Skill> baseSkill, std::shared_ptr<Unit> defender);
public:

	Unit(std::string name);

	void Attack(std::vector<std::shared_ptr<Unit>> targets);
	virtual void OnBeingAttacked(int amount, int accMod, std::shared_ptr<AttackSkill> skill, bool shouldStun) = 0;
	std::vector<std::shared_ptr<Unit>> allies;

	void CalculateSpeed();
	void CalculateNextState();
	void SetupSkills(std::shared_ptr<Unit> owner);

	std::vector<std::shared_ptr<Skill>> GetAllSkills();
	std::shared_ptr<Skill> PickSuitableSkill(int targetPos, SkillType type);
	std::shared_ptr<MoveSkill> GetMoveSkill();

	int GetCalculatedSpeed();
	int GetPos();
	State GetState();
	bool GetIsDead();
	std::string GetName();
	Team GetTeam();

	void ChangeProt(int amount);
	void ChangeHealth(int amount);
	void ChangePos(int place);
	void ChangeNextState(State state);

};