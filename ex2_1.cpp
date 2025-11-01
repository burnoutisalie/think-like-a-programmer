#include <iostream>
using namespace std;

int main() {
	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 8; col++) {
			if (col < row) {
				cout << ' ';
			} else if (col < 8 - row) {
				cout << '#';
			}
		}
		cout << '\n';
	}
	return 0;
}
