#pragma once

class Player
{
public:
	Player();

	~Player();

	void setScore(int);
	int getScore();

private:
	int score;
};
