// includes exercises 2-6 and 2-7
#include <iostream>
using namespace std;

int count_digits(int num);
int power(int base, int exp);
int convert_to_base_10(int num, int base);
int convert_to_base_n(int num, int base);

int main() {
	const char *input = "245";
	int base10 = convert_to_base_10(input, 2);
}

int count_digits(int num) {
	if (num == 0) {
		return 1;
	}
	int count = 0;
	while (num > 0) {
		num /= 10;
		count += 1;
	}
	return count;
}

int power(int base, int exp) {
	int res = 1;
	while (exp > 0) {
		res *= base;
		exp--;
	}
	return res;
}

int convert_to_base_10(int num, int base) {
	int res = 0;
	int n_digits = count_digits(num);
	for (int i = 0; i < n_digits; i++) {
		res += (num % 10) * power(base, i);
		num /= 10;
	}
	return res;
}

int convert_to_base_n(int num, int base) {

}
