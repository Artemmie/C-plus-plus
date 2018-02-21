#include <iostream>
#include <string>
#include "main.h"

int main() {

	do {
		BCgame.reset();
		printIntro();
		playGame();
	} while (playAgain());

	return 0;
}
 
void printIntro() {
	std::cout << "Welcome to Bulls and Cows!";
	std::cout << std::endl;
	std::cout << "Can you guess the " << BCgame.getHiddenWordLength() << " letter isogram I am thinking of?";
	std::cout << std::endl << std::endl;
}

void playGame() {
	while (!BCgame.isGameWon() && BCgame.getCurrentTry() <= BCgame.getMaxTries()) {
		FText guess = getGuess();
		FBullCowCount bullCowCount = BCgame.Submitguess(guess);
		std::cout << "Bulls = " << bullCowCount.Bulls << ". ";
		std::cout << "Cows = " << bullCowCount.Cows;
		std::cout << std::endl << std::endl;
	}
	printGameSummary();
}

FText getGuess() {
	FText guess = "";
	EWordStatus status = EWordStatus::Invalid_Status;
	do {
		std::cout << "Try " << BCgame.getCurrentTry() << " out of " << BCgame.getMaxTries() <<  ". Enter your Guess: ";
		std::getline(std::cin, guess);
		status = BCgame.checkGuessValidity(guess);
		switch (status) {
		case EWordStatus::Wrong_Lenghth:
			std::cout << "Please enter a " << BCgame.getHiddenWordLength() << " letter word." << std::endl << std::endl;
			break;
		case EWordStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters." << std::endl << std::endl;
			break;
		case EWordStatus::Not_Lowercase:
			std::cout << "Please enter in lowercase letters only." << std::endl << std::endl;
			break;
		default:
			break;
		}
	} while (status != EWordStatus::OK);
	return guess;
}

void printGuess(FText guess) {
	std::cout << "Your guess is: " << guess << std::endl;
}

bool playAgain() {
	std::cout << "Want to play again? Y/N" << std::endl;
	FText response = "";
	std::getline(std::cin, response);
	if (response[0] == 'Y' || response[0] == 'y') {
		std::cout << std::endl;
		return true;
	}
	return false;
}

void printGameSummary() {
	if (BCgame.isGameWon()) {
		std::cout << "Congratulations, you won!";
	}
	else std::cout << "Better luck next time!";
	std::cout << std::endl << std::endl;
}