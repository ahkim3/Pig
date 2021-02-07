#pragma once

class Die
{
public:
	Die();

	~Die();

	int getFaceValue();
	void roll();

private:
	int faceValue;
};
