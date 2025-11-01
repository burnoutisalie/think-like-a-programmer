#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	string name;
	for (int i = 0; i < argc; i++) {
		if (argv[i][0] == '-') {
			if (argv[i][1] == '-') {
				if (argv[i] == string("--name")) {
					if (argc >= i + 1) {
						name = argv[i+1];
					} else {
						cout << argv[0] << ": option requires an argument -- " << argv[i] << endl;
					}
				}
			}
		}
	}
	cout << name << endl;
	return 0;
}
