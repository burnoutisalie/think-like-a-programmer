#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	cout << "There are " << argc
		<< " arguments passed." << endl;
	cout << "Program name argv[0] contains: " << argv[0] << endl;
	if (argc >= 2) {
		cout << "First argument argv[1] contains: " << argv[1] << endl;
	}
	return 0;
}
