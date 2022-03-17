#include <iostream>
#include "Game.h"

int main()
{
	// This is here to fix color formatting. Please don't mind it <3
	system("CLS");

	Game game;
	game.Start();

	while (game.gameOver == false)
	{
		game.Tick();
	}

	game.End();
	return 0;
}