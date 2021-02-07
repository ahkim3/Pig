#include "Player.h"

// Default constructor
Player::Player()
{
	score = 0;
}

// Default destructor
Player::~Player()
{
}

// Sets player's score
void Player::setScore(int newScore)
{
	score = newScore;
}

// Returns player's score
int Player::getScore()
{
	return score;
}
