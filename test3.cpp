#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	srand(time(0));
	int secret  = rand() % 100 + 1;
	int guess;
	int attempts = 0;

	cout << "I'm thinking of a number 1-100. Can you guess it?" << endl;
	while (true) {
		cout << "Enter your guess: ";
		cin >> guess;
		attempts++;

		if (guess == secret) {
			cout << "Congratulations! You got it in " << attempts << " attempts!" << endl;
			break;
		} else if (guess > secret) {
			cout << "Too high! Try again." << endl;
		} else {
			cout << "Too low! Try again." << endl;
		}
	}

	return 0;

}
