#include <iostream>
#include <string>
#include "main.h"

int main() {

	do {
		printIntro();
		playGame();
	} while (playAgain());
	return 0;
}

void printIntro() {
	constexpr int WORLD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows!";
	std::cout << std::endl;
	std::cout << "Can you guess the " << WORLD_LENGTH << " letter isogram I am thinking of?";
	std::cout << std::endl << std::endl;
}

void playGame() {
	for (int i = BCGame.getCurrentTry(); i <= BCGame.getMaxTries(); i++) {
		printGuess(getGuess());
		std::cout << std::endl;
	}
}

std::string getGuess() {
	std::cout << "Try " << BCGame.getCurrentTry() << ". Enter your Guess: ";
	std::string guess = "";
	std::getline(std::cin, guess);
	return guess;
}

void printGuess(std::string guess) {
	std::cout << "Your guess is: " << guess << std::endl;
}

bool playAgain() {
	std::cout << "Want to play again? Y/N" << std::endl;
	std::string response = "";
	std::getline(std::cin, response);
	if (response[0] == 'Y' || response[0] == 'y') {
		std::cout << std::endl;
		return true;
	}
	return false;
} 