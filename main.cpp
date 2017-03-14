#include <iostream>
#include <fstream>
#include <string>
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
		unsigned long int tmp = sumfile(nums);
		cout << "Sum:\t" << tmp << endl;
		cout << "Avg:\t" << tmp * 1.0 / nums.length() << endl;
		cout << "Amt:\t" << nums.length() << endl;
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
