#include <iostream>
#include <string>
#include "main.h"
using namespace std;


int main() {

	printIntro();
	playGame();
	return 0;
}

void printIntro() {
	constexpr int WORLD_LENGTH = 5;
	cout << "Welcome to Bulls and Cows!";
	cout << endl;
	cout << "Can you guess the " << WORLD_LENGTH << " letter isogram I am thinking of?";
	cout << endl << endl;
}

void playGame() {
	constexpr int LOOP_LENGTH = 4;
	for (int i = 0; i <= LOOP_LENGTH; i++) {
		printGuess(getGuess());
		cout << endl;
	}
}

string getGuess() {
	cout << "Enter your Guess: ";
	string guess = "";
	getline(cin, guess);
	return guess;
}

void printGuess(string guess) {
	cout << "Your guess is: " << guess << endl;
}