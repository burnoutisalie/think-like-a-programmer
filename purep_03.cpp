#include <iostream>
using namespace std;

int doubleDigitSum(int digit);

int main() {
	char digit;
	int checksum_even = 0;
	int checksum_odd = 0;
	int pos = 1;
	cout << "Enter a number with an even number of digits: ";
	digit = cin.get();
	while (digit != 10) {
		if (int(digit) < 48 || int(digit) > 57) {
			cout << "Enter one number consisting of digits.\n";
			cout << "No other symbols allowed.\n";
			return 1;
		} else {
			if (pos % 2 == 0) {
				checksum_even += digit - '0';
				checksum_odd += doubleDigitSum(digit - '0');
			} else {
				checksum_even += doubleDigitSum(digit - '0');
				checksum_odd += digit - '0';
			}
			digit = cin.get();
			pos++;
		}
	}
	int checksum = 0;
	if ((pos - 1) % 2 == 0) {
		checksum += checksum_even;
	} else {
		checksum += checksum_odd;
	}
	cout << "\nChecksum of digits: " << checksum << ". \n";
	if (checksum % 10 == 0 && pos > 1) {
		cout << "Checksum is divisible by 10. Valid.\n";
	} else {
		cout << "Checksum is not divisible by 10. Invalid.\n";
	}
	return 0;
}

// double the digit provided as an argument, and sum each individual digit of the result
int doubleDigitSum(int digit) {
	int doubled_digit = digit * 2;
	int sum_of_digits = doubled_digit / 10 + doubled_digit % 10;
	return sum_of_digits;
}

