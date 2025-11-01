#include <iostream>
using namespace std;

int main() {
	const int SIZE = 5;
	int scores[SIZE];
	int sum = 0;

	cout << "Enter " << SIZE << " test scores: " << endl;

	for (int i = 0; i < SIZE; i++) {
		cout << "Score " << (i + 1) << ": ";
		cin >> scores[i];
		sum += scores[i];
	}

	cout << "\nAll scores: ";
	for (int i = 0; i < SIZE; i++) {
		cout << scores[i];
		if (i != (SIZE - 1)) {
			cout << " ";
		}
	}

	double average = (double)sum / SIZE;
	int highest = scores[0];
	int lowest = scores[0];

	for (int i = 1; i < SIZE; i++) {
		if (scores[i] > highest) highest = scores[i];
		if (scores[i] < lowest) lowest = scores[i];
	}

	cout << "\nAverage: " << average << endl;
	cout << "Highest: " << highest << endl;
	cout << "Lowest: " << lowest << endl;

	return 0;
}
