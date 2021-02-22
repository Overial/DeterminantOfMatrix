#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>

using namespace std;

void allocate(int**& matr, int n) {
	matr = new int* [n];

	for (int j = 0; j < n; j++) {
		matr[j] = new int[n];
	}
}

void fill(int**& matr, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matr[i][j] = -9 + rand() % 19;
		}
	}
}

void pretty_output(int n) {
	cout << "-";

	for (int i = 0; i < n; i++) {
		cout << "---";
	}

	cout << endl;
}

void print(int**& matr, int n) {
	cout << endl;

	pretty_output(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << "|" << setw(2) << matr[i][j];

			if (j == n - 1) {
				cout << "|\n";

				pretty_output(n);
			}
		}
	}
}

void del(int**& matr, int n) {
	for (int j = 0; j < n; j++) {
		delete[] matr[j];
	}

	delete[] matr;
}

int det(int** matr, int n) {
	int d = 0;
	int number_sign = 0;
	int** sub_matr;
	allocate(sub_matr, n);

	if (n == 1) {
		d = matr[0][0];
	}
	else if (n == 2) {
		d = matr[0][0] * matr[1][1] - matr[0][1] * matr[1][0];
	}
	else if (n >= 3) {
		for (int x = 0; x < n; x++) {
			for (int i = 1; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (j < x) {
						sub_matr[i - 1][j] = matr[i][j];
					}
					else {
						sub_matr[i - 1][j] = matr[i][j + 1];
					}
				}
			}
			d += static_cast<int>(pow(-1, x)) * matr[0][x] * det(sub_matr, n - 1);
		}
	}
	return d;
}

int main() {
	srand(static_cast<unsigned int>(time(0)));

	int n;
	cout << "Enter the dimension of the matrix: ";
	cin >> n;

	int** matr;
	allocate(matr, n);
	fill(matr, n);
	print(matr, n);

	cout << "\nThe determinant equals to " << det(matr, n) << endl;

	del(matr, n);

	return 0;
}