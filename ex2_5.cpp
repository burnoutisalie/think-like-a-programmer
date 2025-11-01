#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	cout << argv[1];
	if (string("10") == argv[1]) {
		cout << "yeah \n";
	} else {
		cout << "wrong \n";
	}
	return 0;
}
