#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int cnt = 0;
	while (cnt < argc) {
		cout << "Argument " << cnt
			<< " is " << argv[cnt]
			<< endl;
		cnt++;
	}
        return 0;
}  
