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
		string nums((istreambuf_iterator<char>(numfile)),
				istreambuf_iterator<char>());

		const int MAX = 64;
		char* tmp;
		char* end;
		long int num = 0;
		streamsize lim = 5;
		
		/* size_t sz; */

		tmp = (char*) malloc(MAX + 1); 

		while (!numfile.eof()) {
			numfile.getline(tmp, lim);

			num += strtol(tmp, &end, 10);
		}
		cout << num << endl;

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
