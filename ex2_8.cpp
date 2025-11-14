// includes exercises 2-6 and 2-7
#include <iostream>
#include <algorithm>
using namespace std;

int char_to_digit(char c);
int digit_to_char(int digit);
int to_decimal(string num, int base);
string from_decimal(int decimal, int base);
string convert_base(string num, int from_base, int to_base);

int main() {
	string s = "a35b2";
	cout << convert_base(s, 15, 8);
}

int char_to_digit(char c) {
	if (c >= '0' && c <= '9') return c - '0';
	if (c >= 'A' && c <= 'F') return c - 'A' + 10;
	if (c >= 'a' && c <= 'f') return c - 'a' + 10;
	return -1;
}

int digit_to_char(int digit) {
	if (digit >= 0 && digit <= 9) return digit + '0';
	if (digit >= 10 && digit <= 15) return digit - 10 + 'A';
	return -1;
}

int to_decimal(string num, int base) {
	int decimal = 0;
	int digit;
	int place_value = 1;
	for (int l = num.length() - 1; l >= 0; l--) {
		digit = char_to_digit(num[l]);
		decimal += digit * place_value;
		place_value *= base;
	}
	return decimal;
}

string from_decimal(int decimal, int base) {
	string num;
	int remainder;
	while (decimal != 0) {
		remainder = decimal % base;
		num.push_back(digit_to_char(remainder));
		decimal /= base;
	}
	reverse(num.begin(), num.end());
	return num;
}

string convert_base(string num, int from_base, int to_base) {
	return from_decimal(to_decimal(num, from_base), to_base);
}
