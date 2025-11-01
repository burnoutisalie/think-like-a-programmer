#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
        int help_long_opt = 0;
        for (int i = 0; i < argc; i++) {
		if (argv[i] == string("--help") || argv[i] == string("-h")) {
			help_long_opt = 1;
                }
        }
        if (help_long_opt) {
                cout << "Help requested!" << endl;
        } else {
                cout << "No help needed." << endl;
        }
        return 0;
}
