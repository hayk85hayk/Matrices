#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

class Matrix {
public:
	unsigned row, column;
	vector <vector<int>> matrix;
	Matrix(unsigned m, unsigned n) {
		column = m;
		row = n;
		matrix.resize(row);
		for (unsigned i = 0; i < matrix.size(); ++i) {
			matrix[i].resize(column, 0);
		}
	}
};


Matrix add_matrix(Matrix a, Matrix b) {
	int i, j;
	Matrix result(a.row, a.column);
	for (i = 0; i < result.row; i++) {
		for (j = 0; j < result.column; j++) {
			result.matrix[i][j] = a.matrix[i][j] + b.matrix[i][j];
		}
	}
	return result;
}
Matrix multiply_matrix(Matrix a, Matrix b)
	{
		unsigned i, j, k;
		int temp;
		Matrix result(a.column, b.row);
		for (i = 0; i < a.row; i++)
		{
			for (j = 0; j < b.column; j++)
			{
				temp = 0;
				for (k = 0; k < a.column; k++)
				{
					temp += a.matrix[i][k] * b.matrix[k][j];
				}
				result.matrix[i][j] = temp;
			}
		}
		return result;
	}

void print_matrix(Matrix a) {
	unsigned i, j;
	for (i = 0; i < a.row; i++) {
		for (j = 0; j < a.column; j++) {
			cout << a.matrix[i][j] << ' ';
		}
		cout << endl;
	}
}

void matrix_from_ifstream(Matrix a, ifstream file, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			file >> a.matrix[i][j];
		}
	}
}

int main() {
	// defining paths to the files
	string path_a = "A.txt", path_b = "B.txt", path_c = "C.txt", path_d = "D.txt", path_y = "Y.txt";
	string elm, sizes_a, sizes_b, sizes_c, sizes_d;
	ifstream afile, bfile, cfile, dfile;
	ofstream yfile;
	// opening files
	afile.open(path_a), bfile.open(path_b), cfile.open(path_c), dfile.open(path_d), yfile.open(path_y);
	if (afile.is_open() && bfile.is_open() && cfile.is_open() && dfile.is_open() && yfile.is_open())
	{
		int qty = 1;
		while (!afile.eof())
		{
			getline(afile, sizes_a), getline(bfile, sizes_b), getline(cfile, sizes_c), getline(dfile, sizes_d);
			assert(sizes_a == sizes_b, "Sizes don't match");
			while (sizes_a[0] == '#') 
			{
				yfile << '#' << qty;
				int m = sizes_a[2] - '0', n = m;
				Matrix a(m, n), b(m, n), c(m, n), d(m, n), y(m, n), tmp1(m, n), tmp2(m, n);
				for (int i = 0; i < m; i++) {
					for (int j = 0; j < n; j++) {
						afile >> a.matrix[i][j];
					}
				}
				for (int i = 0; i < m; i++) {
					for (int j = 0; j < n; j++) {
						bfile >> b.matrix[i][j];
					}
				}
				for (int i = 0; i < m; i++) {
					for (int j = 0; j < n; j++) {
						cfile >> c.matrix[i][j];
					}
				}
				for (int i = 0; i < m; i++) {
					for (int j = 0; j < n; j++) {
						dfile >> d.matrix[i][j];
					}
				}
				tmp1 = add_matrix(a, b);
				tmp2 = add_matrix(c, d);
				y = multiply_matrix(tmp1, tmp2);
				for (int i = 0; i < m; i++) {
					yfile << endl;
					for (int j = 0; j < n; j++) {
						yfile << y.matrix[i][j] << " ";
					}
				}
				yfile << endl;
				getline(afile, sizes_a), getline(bfile, sizes_b), getline(cfile, sizes_c), getline(dfile, sizes_d);
				qty++;
			}
		}
		afile.close(), bfile.close(), cfile.close(), dfile.close(), yfile.close(); // closing files
	}

	else cout << "Unable to open file";

	return 0;
}