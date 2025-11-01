#include <iostream>
using namespace std;

void printChar(int integer, int uppercase_mode, int lowercase_mode, int punctuation_mode);

int main() {
	char digit;
	int integer = 0;
	int uppercase_mode = 1;
	int lowercase_mode = 0;
	int punctuation_mode = 0;
	cout << "Enter the encoded message: ";
	digit = cin.get();
	while (digit != 10) {
		if (int(digit) != 44 && int(digit) != 10) {
			integer = integer * 10 + (digit - '0');
		} else {
			if (integer % 27 == 0) {
				if (uppercase_mode) {
					uppercase_mode = 0;
					lowercase_mode = 1;
				} else if (lowercase_mode) {
					lowercase_mode = 0;
					punctuation_mode = 1;
				}
			} else if (integer % 9 == 0 && punctuation_mode) {
				punctuation_mode = 0;
				uppercase_mode = 1;
			} else {
				printChar(integer, uppercase_mode, lowercase_mode, punctuation_mode);
			}
			integer = 0;
		}
		digit = cin.get();
	}
	if (integer > 0) {
		printChar(integer, uppercase_mode, lowercase_mode, punctuation_mode);
	}
	return 0;
}

void printChar(int integer, int uppercase_mode, int lowercase_mode, int punctuation_mode) {
	if (uppercase_mode) {
		cout << char(integer % 27 + 'A' - 1);
	}
	if (lowercase_mode) {
		cout << char(integer % 27 + 'a' - 1);
	}
	if (punctuation_mode) {
		switch (integer % 9) {
			case 1:
				cout << '!';
				break;
			case 2:
				cout << '?';
				break;
			case 3:
				cout << ',';
				break;
			case 4:
				cout << '.';
				break;
			case 5:
				cout << ' ';
				break;
			case 6:
				cout << ';';
				break;
			case 7:
				cout << '"';
				break;
			case 8:
				cout << '\'';
				break;
		}
	}
}
