#include <iostream>
#include <cstdlib> 
using namespace std;

int main()
{
	int rows, cols;
	cout << "Enter rows: ";
	cin >> rows;
	cout << "Enter columns: ";
	cin >> cols;

	int** matrix = new int* [rows];
	for (int i = 0; i < rows; i++) {
		matrix[i] = new int[cols];
		for (int j = 0; j < cols; j++) {
			matrix[i][j] = rand() % 21 - 10;
		}
	}

	cout << "\nMatrix:\n";
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}

	int* max_elements = new int[rows];
	for (int i = 0; i < rows; i++) {
		max_elements[i] = -1;
		for (int j = 0; j < cols; j++) {
			if (matrix[i][j] > 0 && (max_elements[i] == -1 || matrix[i][j] > max_elements[i])) {
				max_elements[i] = matrix[i][j];
			}
		}
	}


	cout << "\nMax positive elements of every rows:\n";
	for (int i = 0; i < rows; i++) {
		if (max_elements[i] == -1) {
			cout << "In row " << i + 1 << " no positive elements\n";
		}
		else {
			cout << "Max positive element in row " << i + 1 << " = " << max_elements[i] << endl;
		}
	}

	int* positive_elements = new int[rows];
	int j = 0;
	for (int i = 0; i < rows; i++) {
		if (max_elements[i] > 0) {
			positive_elements[j] = max_elements[i];
			j++;
		}
	}

	if (j == 0) {
		cout << "\nThere is no positive elements in the matrix\n";
	}
	else {
		cout << "\nArray of max positive elements:\n";
		for (int i = 0; i < j; i++) {
			cout << positive_elements[i] << "\t";
		}
		cout << endl;
	}

	for (int i = 0; i < rows; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
	delete[] max_elements;
	delete[] positive_elements;

	return 0;
}