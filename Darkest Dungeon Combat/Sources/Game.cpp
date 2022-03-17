#include "Game.h"
#include "Utility.h"

#include "Crusader.h"
#include "Vestal.h"
#include "Bone_Soldier.h"
#include "Bone_Defender.h"
#include "MoveSkill.h"

void Game::WelcomeScreen()
{
	std::cout << "Welcome to Darkest Dungeon Combat Simulator" << std::endl;
	std::cout << "This project was made by Yigit Eren, Fahrican Elidemir and Ata Baris Canalp." << std::endl << std::endl;

	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}

void Game::EndScreen()
{
	std::cout << victoryString << std::endl << "Exiting the game in 10 seconds...";
	std::this_thread::sleep_for(std::chrono::milliseconds(1000 * 10));
}

void Game::CheckGameOver()
{
	bool isAllHeroesDead = true;
	bool isAllMonstersDead = true;

	int deadHeroes = 0;
	int deadMonsters = 0;

	for (int i = 0; i < heroes.size(); i++)
		if (!heroes[i]->GetIsDead()) isAllHeroesDead = false;
		else deadHeroes++;

	for (int i = 0; i < monsters.size(); i++)
		if (!monsters[i]->GetIsDead()) isAllMonstersDead = false;
		else deadMonsters++;

	gameOver = isAllHeroesDead || isAllMonstersDead;
	
	if (isAllMonstersDead) victoryString = "\x1B[32mHeroes claim the victory!\033[0m";
	else if (isAllHeroesDead) victoryString = "\x1B[31mMonsters claim the victory!\033[0m";

	victoryString += "\n";

	victoryString += "\x1B[36mAlive Heroes\033[0m\n";
	if (isAllHeroesDead) victoryString += "\x1B[31mNone\033[0m\n";
	else for (int i = 0; i < heroes.size(); i++)
		if (heroes[i]->GetIsDead() == false)
			victoryString += "- \x1B[33m" + heroes[i]->GetName() + "\033[0m\n";

	victoryString += "\x1B[36mAlive Monsters\033[0m\n";
	if (isAllMonstersDead) victoryString += "\x1B[31mNone\033[0m\n";
	else for (int i = 0; i < monsters.size(); i++)
		if (monsters[i]->GetIsDead() == false)
			victoryString += "- \x1B[33m" + monsters[i]->GetName() + "\033[0m\n";

}

void Game::CheckRoundOver()
{
	if (attackQueue.size() == 0)
	{
		std::cout << "\x1B[32mRound " << currentRound << " finished!\033[0m\t\t" << std::endl << std::endl;
		
		TickSkills();
		hasRoundStarted = false;
		currentRound++;

		return;
	}
}

void Game::TickSkills()
{
	for (int i = 0; i < heroes.size(); i++)
		for (int j = 0; j < heroes[i]->GetAllSkills().size(); j++)
			heroes[i]->GetAllSkills()[j]->SkillTick();

	for (int i = 0; i < monsters.size(); i++)
		for (int j = 0; j < monsters[i]->GetAllSkills().size(); j++)
			monsters[i]->GetAllSkills()[j]->SkillTick();
}

void Game::DoNextAttack(std::shared_ptr<Unit> nextAttacker)
{
	if (nextAttacker->GetIsDead())
	{
		attackQueue.erase(attackQueue.begin());
		return;
	}

	Team targetTeam = nextAttacker->GetTeam() == Team::Heroes ? Team::Monsters : Team::Heroes;
	std::vector<std::shared_ptr<Unit>> possibleTargets = CalculateTargets(targetTeam);

	nextAttacker->Attack(possibleTargets);
}

void Game::CalculateAttackQueue()
{

	std::cout << std::endl << "\x1B[32m- Round " << currentRound << " Begins -\033[0m\t\t" << std::endl << std::endl;

	std::vector<std::shared_ptr<Unit>> allUnits;
	allUnits.reserve(heroes.size() + monsters.size());

	for (int i = 0; i < heroes.size(); i++)
		if (!heroes[i]->GetIsDead()) allUnits.push_back(heroes[i]);

	for (int i = 0; i < monsters.size(); i++)
		if(!monsters[i]->GetIsDead()) allUnits.push_back(monsters[i]);

	for (int i = 0; i < allUnits.size(); i++)
		allUnits[i]->CalculateSpeed();

	std::sort(allUnits.begin(), allUnits.end(), Utility::CompareUnitSpeeds);

	std::reverse(allUnits.begin(), allUnits.end());
	attackQueue = allUnits;
	hasRoundStarted = true;
}

std::vector<std::shared_ptr<Unit>> Game::CalculateTargets(Team targetTeam)
{

	std::vector<std::shared_ptr<Unit>> targetableHeroes;
	std::vector<std::shared_ptr<Unit>> targetableMonsters;

	for (int i = 0; i < heroes.size(); i++)
		if (!heroes[i]->GetIsDead()) targetableHeroes.push_back(heroes[i]);

	for (int i = 0; i < monsters.size(); i++)
		if (!monsters[i]->GetIsDead()) targetableMonsters.push_back(monsters[i]);

	if (targetTeam == Team::Heroes)
		return targetableHeroes;
	else
		return targetableMonsters;

}

std::shared_ptr<Unit> Game::GetUnitInPosition(int pos, Team team)
{
	std::shared_ptr<Unit> unit = nullptr;

	if(team == Team::Heroes)
		for (int i = 0; i < heroes.size(); i++)
		{
			if (heroes[i]->GetPos() == pos) unit = heroes[i];
		}
	else
		for (int i = 0; i < monsters.size(); i++)
		{
			if (monsters[i]->GetPos() == pos) unit = monsters[i];
		}

	return unit;
}

void Game::Start()
{
	WelcomeScreen();

	timeBetweenRounds = 1000;
	timeBetweenEvents = 600;

	currentRound = 1;

	auto crusader1 = std::make_shared<Crusader>("Crusader #1");
	auto crusader2 = std::make_shared<Crusader>("Crusader #2");
	auto vestal1 = std::make_shared<Vestal>("Vestal #1");
	auto vestal2 = std::make_shared<Vestal>("Vestal #2");

	auto bone_soldier1 = std::make_shared<Bone_Soldier>("Bone Soldier #1");
	auto bone_defender1 = std::make_shared<Bone_Defender>("Bone Defender #1");
	auto bone_soldier2 = std::make_shared<Bone_Soldier>("Bone Soldier #2");
	auto bone_defender2 = std::make_shared<Bone_Defender>("Bone Defender #2");

	heroes.push_back(crusader1);
	heroes.push_back(crusader2);
	heroes.push_back(vestal1);
	heroes.push_back(vestal2);

	for (int i = 0; i < heroes.size(); i++)
	{
		heroes[i]->ChangePos(i + 1);
		heroes[i]->SetupSkills(heroes[i]);
		heroes[i]->allies = heroes;

	}

	monsters.push_back(bone_soldier1);
	monsters.push_back(bone_defender1);
	monsters.push_back(bone_soldier2);
	monsters.push_back(bone_defender2);

	for (int i = 0; i < monsters.size(); i++)
	{
		monsters[i]->ChangePos(i + 1);
		monsters[i]->SetupSkills(monsters[i]);
		monsters[i]->allies = monsters;
	}
}

void Game::Tick()
{

	if (hasRoundStarted == false)
		CalculateAttackQueue();

	CheckRoundOver();

	if (attackQueue.size() > 0)
	{
		std::shared_ptr<Unit> nextUnitInQueue = attackQueue[0];
		nextUnitInQueue->CalculateNextState();

		if (!nextUnitInQueue->GetIsDead())
		{
			if (nextUnitInQueue->GetState() == State::WillAttackOrUtility)
				DoNextAttack(nextUnitInQueue);
			else
			{
				int random = Utility::GenerateRandom(0, 100);
				std::shared_ptr<Unit> targetUnitToSwap;

				if ((random <= 50 && nextUnitInQueue->GetPos() != (nextUnitInQueue->GetTeam() == Team::Heroes ? heroes.size() : monsters.size())) || nextUnitInQueue->GetPos() == 1)
					targetUnitToSwap = GetUnitInPosition(nextUnitInQueue->GetPos() + 1, nextUnitInQueue->GetTeam());
				else
					targetUnitToSwap = GetUnitInPosition(nextUnitInQueue->GetPos() - 1, nextUnitInQueue->GetTeam());

				nextUnitInQueue->GetMoveSkill()->SwapPositions(nextUnitInQueue, targetUnitToSwap);

			}

			if (nextUnitInQueue->GetState() == State::WillForceMoveBack && nextUnitInQueue->GetPos() != 4)
			{
				std::shared_ptr<Unit> targetUnitToSwap;
				targetUnitToSwap = GetUnitInPosition(nextUnitInQueue->GetPos() + 1, nextUnitInQueue->GetTeam());
				nextUnitInQueue->GetMoveSkill()->SwapPositions(nextUnitInQueue, targetUnitToSwap);
			}

			if (nextUnitInQueue->GetState() == State::WillForceMoveFront && nextUnitInQueue->GetPos() != 1)
			{
				std::shared_ptr<Unit> targetUnitToSwap;
				targetUnitToSwap = GetUnitInPosition(nextUnitInQueue->GetPos() + -1, nextUnitInQueue->GetTeam());
				nextUnitInQueue->GetMoveSkill()->SwapPositions(nextUnitInQueue, targetUnitToSwap);
			}

			std::cout << std::endl << "-------------------------------" << std::endl << std::endl;
		}

		attackQueue.erase(attackQueue.begin());
	}

	CheckGameOver();

	if (hasRoundStarted == true)
		std::this_thread::sleep_for(std::chrono::milliseconds(timeBetweenEvents));
	else {
		std::this_thread::sleep_for(std::chrono::milliseconds(timeBetweenRounds));
		system("CLS");
	}
}

void Game::End()
{
	EndScreen();
}