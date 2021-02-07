#include "Die.h"
#include <cstdlib>
#include <time.h>

// Default constructor
Die::Die()
{
	srand(time(NULL));
	roll();
}

// Default destructor
Die::~Die()
{
}

// Getter method for faceValue
int Die::getFaceValue()
{
	return faceValue;
}

// Rolls die
void Die::roll()
{
	faceValue = (rand() % 6) + 1; // Outputs random number from [1-6]
}
