#include "DiceGame.h"
#include "Die.h"
#include "Player.h"
#include <iostream>

using namespace std;


// Default constructor
DiceGame::DiceGame()
{
	player = 1; // Sets first player to Player 1
	play();
}

// Default destructor
DiceGame::~DiceGame()
{
}

// Starts and plays game
void DiceGame::play()
{
	endGame = false;

	// Game continues until a player scores at least 100
	while ((playerOne.getScore() < 100) && (playerTwo.getScore() < 100))
		turn(player);

	// Declares winner
	if (playerOne.getScore() >= 100)
		cout << "Player One ";
	else if (playerTwo.getScore() >= 100)
		cout << "Player Two ";
	cout << "won. Game Over!";

}

// Plays selected player's turn
void DiceGame::turn(int& player)
{
	int turnTotal = 0, holdInput = 1;
	bool endTurn = false, doubles;

	// Identifies correct player before continuing
	cout << "Player " << player << ", it is now your turn." << endl;

	// Displays current score
	cout << "Your score is currently: " << combinedScore(player, turnTotal) 
		<< endl << endl;

	// Player keeps rolling until they decide to hold or game is over
	while (!endTurn && !endGame)
	{
		doubles = false;
		turnTotal = 0;

		// Prompts user to roll dice if not continuing a turn
		if (holdInput == 1 && !doubles)
		{
			cout << "Continue your turn to roll the dice." << endl;
			system("pause");
			cout << endl;
		}

		// Roll dice
		dieOne.roll();
		faceValueOne = dieOne.getFaceValue();
		dieTwo.roll();
		faceValueTwo = dieTwo.getFaceValue();
		cout << "Die 1 rolled a: " << faceValueOne << endl;
		cout << "Die 2 rolled a: " << faceValueTwo << endl << endl;

		// Apply game rules
		// If two 1s are rolled, entire score is lost and turn ends
		if ((faceValueOne == 1) && (faceValueTwo == 1))
		{
			// Sets player's score to 0
			if (player == 1)
				playerOne.setScore(0);
			else
				playerTwo.setScore(0);

			turnTotal = 0;
			endTurn = true; // Ends turn

			cout << "You rolled two 1s. Your score has been reset to 0 and "
				<< "your turn has ended." << endl;
		}
		// If doubles are rolled, sum is added but player must roll again
		else if (faceValueOne == faceValueTwo)
		{
			turnTotal += (faceValueOne + faceValueTwo);
			doubles = true;

			cout << "You rolled double " << faceValueOne << "s. The sum of "
				"your dice has been added to your score. You must roll "
				<< "again." << endl;
		}
		// If neither shows a 1, their sum is added to turn total
		else if ((faceValueOne != 1) && (faceValueTwo != 1))
		{
			turnTotal += (faceValueOne + faceValueTwo);

			cout << "The sum of your dice has been added to your score."
				<< endl;
		}
		// A single 1 was rolled, player scores nothing and turn ends
		else
		{
			endTurn = true;
			cout << "You rolled a single 1. You scored nothing and your turn "
				<< "has ended." << endl;
		}

		// Sets and displays current score
		cout << endl << "Your score is now: " 
			<< combinedScore(player, turnTotal) << endl << endl;
		setCombinedScore(player, turnTotal);

		// Checks if player has won the game
		if ((playerOne.getScore() >= 100) || (playerTwo.getScore() >= 100))
			endGame = true;

		if (!endTurn && !doubles && !endGame)
		{
			// Asks player what they would like to do next
			cout << "Please enter 1 to hold or 2 to continue: ";
			cin >> holdInput;
			if (holdInput == 1)
				endTurn = true;
			cout << endl << endl;
		}
		else
		{
			// Pauses before next player's turn
			system("pause");

			if (!endGame)
				cout << endl << endl; // Adds extra newlines if end of game
		}
	}

	// Switches player for next turn
	player = switchPlayer(player);
	
	system("cls");
}

// Returns non-current player number
int DiceGame::switchPlayer(int currentPlayer)
{
	if (currentPlayer == 1)
		return 2;
	else
		return 1;
}

// Returns player's score at certain point in turn
int DiceGame::combinedScore(int player, int turnTotal)
{
	if (player == 1)
		return (playerOne.getScore() + turnTotal);
	else
		return (playerTwo.getScore() + turnTotal);
}

// Adds turnTotal to player's score
void DiceGame::setCombinedScore(int player, int turnTotal)
{
	if (player == 1)
		playerOne.setScore(combinedScore(player, turnTotal));
	else
		playerTwo.setScore(combinedScore(player, turnTotal));
}
