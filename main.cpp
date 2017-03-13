#include <iostream>
#include <fstream>
#include <string>
#include "file.hpp"

using namespace std;

int
main(int argc, char *argv[]) {
	if (argc == 1) {
		cout << "Please specify a file.\n";
		return 1;
	} else if (argc == 2) {
		ifstream numfile;

		numfile.open(argv[1], ifstream::in);

		if (numfile.is_open())
			test_print(argv[1]);
		return 0;
	} else {
		return 2;
	}
}
