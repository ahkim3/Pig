#pragma once
#include "Die.h"
#include "Player.h"

class DiceGame
{
public:
	DiceGame();

	~DiceGame();

private:
	void play();
	void turn(int&);
	int switchPlayer(int);
	int combinedScore(int, int);
	void setCombinedScore(int, int);

	Die dieOne, dieTwo;
	Player playerOne, playerTwo;
	int faceValueOne, faceValueTwo, player;
	bool endGame;
};
