#include <iostream>
using namespace std;

int main() {
	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 14; col++) {
			if (row < 4) {
				if (col < 7) {
					if (col < row) {
						cout << ' ';
					} else if (col <= row * 2) {
						cout << '#';
					} else {
						cout << ' ';
					}
				} else {
					if (col < 14 - 1 - row * 2) {
						cout << ' ';
					} else if (col < 14 - row) {
						cout << '#';
					}
				}
			} else {
				if (col < 7) {
					if (col < 8 - 1 - row) {
						cout << ' ';
					} else if (col <= (8 - 1 - row) * 2) {
						cout << '#';
					} else {
						cout << ' ';
					}
				} else {
					if (col < 14 - 1 - (8 - 1 - row) * 2) {
						cout << ' ';
					} else if (col <= 14 - (8 - row)) {
						cout << '#';
					} else {
						cout << ' ';
					}
				}
			}
		}
		cout << '\n';
	}
	return 0;
}
