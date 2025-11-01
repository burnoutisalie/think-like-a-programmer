#include <iostream>
using namespace std;

int main() {
	int m = 9;
	int n = 17;
	int cnt = 0;
	int start = n / 2 + 2;
	char symbol = '*';
	for (int row = 0; row < m; row++) {
		if (row < 5) {
			cnt++;
			start -= 2;
		} else {
			cnt--;
			start += 2;
		}
		int cnt_cpy = cnt;
		int start_cpy = start;
		for (int col = 0; col < n; col++) {
			if (cnt_cpy && col == start_cpy) {
				cout << symbol;
				cnt_cpy -= 1;
				start_cpy += 4;
			} else {
				cout << ' ';
			}
		}
		cout << '\n';
	}
	return 0;
}
