#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;


void printIntro();
void playGame();
void printGuess(FText);
void printGameSummary();
bool playAgain();
FBullCowGame BCgame;
FText getGuess();
