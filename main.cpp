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
		/* processes input file to string */
		ifstream numfile(argv[1]);

		const int MAX = 64;
		char* end;
		long int num = 0;
		streamsize lim = 5;
		
		while (!numfile.eof()) {
			char* tmp;
			tmp = (char*) malloc(MAX + 1); 
			numfile.getline(tmp, lim);
			num += strtol(tmp, &end, 10);
			free(tmp);
		}
		cout << num << endl;

		return 0;
	} else {
		cerr << "Invalid arguments\n";
		return EX_USAGE;
	}
}

unsigned long int
sumfile(string file) {
	unsigned long int sum = 0;
	unsigned int i;
	for (i = 0; i < file.length(); i++)
		sum += file[i] - 30;
	return sum;
}
