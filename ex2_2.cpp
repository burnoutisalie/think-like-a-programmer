#include <iostream>
using namespace std;

int main() {
	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 8; col++) {
			if (row / 4 == 0) {
				if (col < 3 - row) {
					cout << ' ';
				} else if (col < 8 - (3 - row)) {
					cout << '#';
				}
			} else if (row / 4 == 1) {
				if (col < row - 4) {
					cout << ' ';
				} else if (col < 8 - (row - 4)) {
					cout << '#';
				}
			}
		}
		cout << '\n';
	}
	return 0;
}
