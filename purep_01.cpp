#include <iostream>
using namespace std;
  // PROBLEM: HALF OF A SQUARE

  /* Write a program that uses only two output statements, cout << "#" and cout << "\n", to produce a pattern of hash symbols
  shaped like half of a perfect 5x5 square:
  #####
  ####
  ###
  ##
  #
  */

int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5 - i; j++ ) {
			cout << "#";
		}
		cout << "\n";
	}

	return 0;
}
