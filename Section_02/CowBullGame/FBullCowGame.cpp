#include "FBullCowGame.h"
#include <map>
#define TMap std::map

void FBullCowGame::reset()
{
	const FString hiddenWord = "planet";
	myHiddenWord = hiddenWord;
	myCurrentTry = 1;
	gameWon = false;
}

int FBullCowGame::getMaxTries() const {
	TMap <int32, int32> wordLengthToMaxTries{ {3, 4},  {4, 6}, {5, 9}, {6, 13} };
	return wordLengthToMaxTries[myHiddenWord.length()];

}
int FBullCowGame::getCurrentTry() const { return myCurrentTry; }
int32 FBullCowGame::getHiddenWordLength() const { return myHiddenWord.length(); }
bool FBullCowGame::isGameWon() const {  return gameWon; }

bool FBullCowGame::isIsogram(FString word) const{
	if (word.length() <= 1)
		return true;
	TMap <char, bool> letterSeen;
	for (auto letter : word)
	{
		letter = tolower(letter);
		if (letterSeen[letter]) {
			return false;
		}
		else {
			letterSeen[letter] = true;
		}
			
	}
	return true;
}

EWordStatus FBullCowGame::checkGuessValidity(FString guess) const { 
	if (!isIsogram(guess)) {
		return EWordStatus::Not_Isogram;
	}
	else if (!isLowerCase(guess)) {
		return EWordStatus::Not_Lowercase;
	}
	else if (guess.length() != getHiddenWordLength()) {
		return EWordStatus::Wrong_Lenghth;
	}
	else return EWordStatus::OK;
}

bool FBullCowGame::isLowerCase(FString guess) const
{
	for (auto letter : guess) {
		if (!islower(letter)) {
			return false;
		}
	}
	return true;
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
	if (bullCowCount.Bulls == hiddenWordLength) {
		gameWon = true;
	}
	else gameWon = false;
	return bullCowCount;
}
