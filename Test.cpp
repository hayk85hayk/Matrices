#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

int main() {
	ifstream yfile, ynumpyfile;
	string y, ynumpy;
	string path_y = "Y.txt", path_y_numpy = "Y_numpy.txt";
	yfile.open(path_y), ynumpyfile.open(path_y_numpy);
	if (ynumpyfile.is_open() && yfile.is_open())
	{
		while (!yfile.eof())
		{
			yfile >> y;
			ynumpyfile >> ynumpy;
			if (y != ynumpy) { cout << "Test is failed"; break; }
		}		
		yfile.close(), ynumpyfile.close(); // closing files
		cout << "Test succeed" << endl;
		system("pause");
	}
	else cout << "Unable to open file";

	return 0;
}