#include <iostream>
#include <cmath>
using namespace std;

double calcRectangleArea(double width, double length) {
	double area = width * length;
	return area;
}

bool isPrime(int n) {
	if (n <= 1) {
		return false;
	}
	if (n == 2 || n == 3) {
		return true;
	}
	if (n % 2 == 0 || n % 3 == 0) {
		return false;
	}
	for (int i = 5; i <= sqrt(n); i = i + 6) {
		if (n % i == 0 || n % (i + 2) == 0) {
			return false;
		}
	}
	return true;
}

int reverseNumber(int n) {
	int reversed = 0;
	if (n == 0) {
		return n;
	}
	while (n) {
		reversed = reversed * 10 + n % 10;
		n = n / 10;
	}
	return reversed;
}

int main() {
	double width = 4, length = 25;
	double area = calcRectangleArea(width, length);

	cout << "Area of a rectangle with " << width << "cm width and " << length << "cm length is: " << area << "cm^2" << endl;

	int num1 = 13, num2 = 77, num3 = 0;
	cout << "Number " << num1 << " is ";
	if (isPrime(num1)) {
		cout << "prime." << endl;
	} else {
		cout << "not prime." << endl;
	}
	cout << "Number " << num2 << " is ";
	if (isPrime(num2)) {
		cout << "prime." << endl;
	} else {
		cout << "not prime." << endl;
	}
	cout << "Number " << num3 << " is ";
	if (isPrime(num3)) {
		cout << "prime." << endl;
	} else {
		cout << "not prime." << endl;
	}

	int rnum1 = 5912, rnum2 = 0, rnum3 = -1245;
	
	cout << "Reverse of " << rnum1 << " is " << reverseNumber(rnum1) << endl;
	cout << "Reverse of " << rnum2 << " is " << reverseNumber(rnum2) << endl;
	cout << "Reverse of " << rnum3 << " is " << reverseNumber(rnum3) << endl;


	return 0;
}
