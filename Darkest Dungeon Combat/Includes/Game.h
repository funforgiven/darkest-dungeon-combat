#pragma once

#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <algorithm>
#include <memory>
#include <typeinfo>
#include <type_traits>

#include "Unit.h"

class Game
{
protected:
	std::vector<std::shared_ptr<Unit>> heroes;
	std::vector<std::shared_ptr<Unit>> monsters;
	std::vector<std::shared_ptr<Unit>> attackQueue;

	std::string victoryString;

	int currentRound;

	int timeBetweenRounds;
	int timeBetweenEvents;
	
	void WelcomeScreen();
	void EndScreen();
	void CheckGameOver();
	void CheckRoundOver();

	void TickSkills();

	void DoNextAttack(std::shared_ptr<Unit> nextAttacker);
	void CalculateAttackQueue();
	std::vector<std::shared_ptr<Unit>> CalculateTargets(Team targetTeam);
	std::shared_ptr<Unit> GetUnitInPosition(int pos, Team team);


public:

	bool gameOver = false;
	bool hasRoundStarted = false;

	void Start();
	void Tick();
	void End();

};

