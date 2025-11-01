#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
        bool is_verbose = false;
        bool is_count = false;
        int count;
        for (int i = 1; i < argc; i++) {
                if (argv[i] == string("--verbose")) {
                        is_verbose = true;
                } else if (argv[i] == string("--count")) {
                        if (argc - 1 >= i + 1) {
				try {
                                	count = stoi(argv[i+1]);
                                	is_count = true;
                                	i++;
				} catch (const invalid_argument & e) {
					cerr << argv[0] << ": Error converting '" << argv[i+1] << "': Invalid argument - " << e.what() << endl;
					i++;
				}
                        } else {
                                cerr << argv[0] << ": option reqires an argument -- " << argv[i] << endl;
                                return 1;
                        }
                } else {
			cerr << argv[0] << ": Error: unknown option -- " << "'" << argv[i] << "'" << endl;
		}
        }
        if (is_verbose) {
                cout << "Verbose mode is ON." << endl;
        }
        if (is_count) {
                cout << "Count is: " << count << endl;
        }
        cout << count << endl;
        return 0;
}
