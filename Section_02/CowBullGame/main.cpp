#include <iostream>
#include <string>
using namespace std;

void printIntro();
void getGuess();

int main() {
	printIntro();
	getGuess();
	return 0;
}

void printIntro() {
	constexpr int WORLD_LENGTH = 5;
	cout << "Welcome to Bulls and Cows!\n";
	cout << "Can you guess the " << WORLD_LENGTH << " letter isogram I am thinking of?\n";
}
void getGuess() {
	cout << "Enter your Guess: ";
	string  guess = "";
	getline(cin, guess);
	cout << "Your guess is: " << guess << "\n";
}