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

		/* information output */

		/*
		unsigned long int tmp = sumfile(nums);
		cout << "Sum:\t" << tmp << endl;
		cout << "Avg:\t" << tmp * 1.0 / nums.length() << endl;
		cout << "Amt:\t" << nums.length() << endl;
		return 0;
		*/

		const int MAX = 256;
		char* tmp;
		int num;
		streamsize lim = 256;
		size_t sz;

		tmp = (char*) malloc(MAX + 1); 
		while (!numfile.eof()) {
			numfile.getline(tmp, lim, '\n');
			string str(tmp);
			num += stoi(tmp, &sz);
		}
		cout << num;

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
