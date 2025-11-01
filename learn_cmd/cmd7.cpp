#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	bool is_verbose = false;
	bool is_debug = false;
	for (int i = 0; i < argc; i++) {
		string arg = argv[i];
		if (arg.length() > 1 && arg[0] == '-' && arg[1] != '-') {
			for (size_t j = 1; j < arg.length(); j++) {
				switch (arg[j]) {
					case 'v':
						is_verbose = true;
						break;
					case 'd':
						is_debug = true;
						break;
					default:
						cerr << argv[0] << ": invalid option -- "
							<< "'" << arg[j] << "'" << endl;
				}
			}
		}
	}
	if (is_verbose) {
		cout << "Verbose mode ON" << endl;
	}
	if (is_debug) {
		cout << "Debug mode ON" << endl;
	}
	return 0;
}
