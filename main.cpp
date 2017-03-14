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

		const int MAX = 128;
		char* tmp;
		long int num = 0;
		int n;
		streamsize lim = 5;
		
		/* size_t sz; */

		tmp = (char*) malloc(MAX + 1); 

		while (!numfile.eof()) {
			numfile.getline(tmp, lim);

			sscanf(tmp, "%d", &n);
			num += n;
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
