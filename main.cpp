#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include <sysexits.h>

using namespace std;

unsigned long	sumfile(string);

int
main(int argc, char *argv[]) {
	if (argc == 1) {
		cout << "Please specify a file.\n";
		return EX_USAGE;
	} else if (argc == 2) {
		ifstream numfile(argv[1]);

		const int MAX = 64;
		char* end;
		unsigned long long int num = 0;
		unsigned long int tally = 0;
		streamsize lim = 5;
		
		while (!numfile.eof()) {
			char* tmp;
			tmp = (char*) malloc(MAX + 1); 
			numfile.getline(tmp, lim);
			num += strtol(tmp, &end, 10);
			tally++;
			free(tmp);
		}
		cout << "Amt:\t" << tally << endl;
		cout << "Sum:\t" << num << endl;
		cout << "Avg:\t" << num * 1.0 / tally << endl;

		return 0;
	} else {
		cerr << "Invalid arguments\n";
		return EX_USAGE;
	}
}
