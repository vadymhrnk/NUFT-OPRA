#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void shellSort(int** matrix, int rows, int columns) {
	for (int col = 0; col < columns; col++) {
		for (int gap = rows / 2; gap > 0; gap /= 2) {
			for (int i = gap; i < rows; i++) {
				int temp = matrix[i][col];
				int j;
				for (j = i; j >= gap && matrix[j - gap][col] < temp; j -= gap) {
					matrix[j][col] = matrix[j - gap][col];
				}
				matrix[j][col] = temp;
			}
		}
	}
}

void printMatrix(int** arr, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

int main() {

	srand(time(0));
	const int n = 5;
	int** matrix = new int* [n];

	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = rand() % 50;
		}
	}

	cout << "Initial:\n";
	printMatrix(matrix, n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++)
		{
			shellSort(matrix, j, i);
		}
	}

	cout << "Sorted:\n";
	printMatrix(matrix, n);

	for (int i = 0; i < n; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;

	return 0;
}
