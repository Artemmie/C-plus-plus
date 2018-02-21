#include "FBullCowGame.h"

void FBullCowGame::reset()
{
	constexpr int32 MAX_TRIES = 5;
	const FString hiddenWord = "planet";
	myHiddenWord = hiddenWord;
	myCurrentTry = 1;
	myMaxTries = MAX_TRIES;
	
}

int FBullCowGame::getMaxTries() const { return myMaxTries; }
int FBullCowGame::getCurrentTry() const { return myCurrentTry; }
int32 FBullCowGame::getHiddenWordLength() const { return myHiddenWord.length(); }
bool FBullCowGame::isGameWon() const { return false; }
EWordStatus FBullCowGame::checkGuessValidity(FString guess) const { 
	if (false) {
		return EWordStatus::Not_Isogram;
	}
	else if (false) {
		return EWordStatus::Not_Lowercase;
	}
	else if (guess.length() != getHiddenWordLength()) {
		return EWordStatus::Wrong_Lenghth;
	}
	else return EWordStatus::OK;
}
FBullCowGame::FBullCowGame() { reset(); }

FBullCowCount FBullCowGame::Submitguess(FString guess)
{
	myCurrentTry++;
	FBullCowCount bullCowCount;
	int32 hiddenWordLength = myHiddenWord.length();
	for (int32 i = 0; i < hiddenWordLength; i++) {
		for (int32 j = 0; j < hiddenWordLength; j++) {
			if (guess[i] == myHiddenWord[j]) {
				if (i == j) { bullCowCount.Bulls++; }
				else { bullCowCount.Cows++; }
			}
		}
	}
	return bullCowCount;
}
