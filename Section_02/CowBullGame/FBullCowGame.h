#pragma once
#include <string>


class FBullCowGame {
public:
	FBullCowGame();
	void reset();
	int getMaxTries() const;
	int getCurrentTry() const;
	bool isGameWon() const;
	bool checkGuessValidity(std::string);

private:
	int myCurrentTry;
	int myMaxTries;
};