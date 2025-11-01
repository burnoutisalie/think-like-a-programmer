#include <iostream>
using namespace std;

int main() {
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 4 - abs(4 - i - 1); j++) {
			cout << "#";
		}
		cout << "\n";
	}
	return 0;
}
