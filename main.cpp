#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void		testprint(string);
unsigned long	sumfile(string);

int
main(int argc, char *argv[]) {
	if (argc == 1) {
		cout << "Please specify a file.\n";
		return 1;
	} else if (argc == 2) {
		ifstream numfile(argv[1]);
		string nums((istreambuf_iterator<char>(numfile)),
				istreambuf_iterator<char>());

		testprint(argv[1]);
		cout << sumfile(nums) << endl;
		return 0;
	} else {
		return 2;
	}
}

void
testprint(string foo) {
	cout << foo << endl;
}

unsigned long int
sumfile(string file) {
	unsigned long int sum = 0;
	unsigned int i;
	for (i = 0; i < file.length(); i++)
		sum += file[i] - 30;
	return sum;
}

