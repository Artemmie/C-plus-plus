#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum EWordStatus {
	OK,
	Not_Isogram,
	Wrong_Lenghth,
	Not_Lowercase,
	Invalid_Status
};


class FBullCowGame {
public:
	FBullCowGame();
	int32 getMaxTries() const;
	int32 getCurrentTry() const;
	int32 getHiddenWordLength() const;
	bool isGameWon() const;
	EWordStatus checkGuessValidity(FString) const;

	FBullCowCount Submitguess(FString);
	void reset();

private:
	int32 myCurrentTry;
	int32 myMaxTries;
	FString myHiddenWord;
};