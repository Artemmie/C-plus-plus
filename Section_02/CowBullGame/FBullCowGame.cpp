#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
	reset();
}

void FBullCowGame::reset()
{
	constexpr int MAX_TRIES = 5;
	myCurrentTry = 1;
	myMaxTries = MAX_TRIES;
}

int FBullCowGame::getMaxTries() const
{
	return myMaxTries;
}

int FBullCowGame::getCurrentTry() const
{
	return myCurrentTry;
}

bool FBullCowGame::isGameWon() const
{
	return false;
}

bool FBullCowGame::checkGuessValidity(std::string)
{
	return false;
}
