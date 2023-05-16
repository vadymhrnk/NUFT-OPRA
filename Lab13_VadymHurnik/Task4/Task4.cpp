#include <iostream>

using namespace std;

void calculateRowSums(int** matrix, int rowCount, int* rowSums) {
	for (int i = 0; i < rowCount; i++)
	{
		int sum = 0;
		for (int j = 0; j < i; j++)
		{
			sum += matrix[i][j];
		}
		rowSums[i] = sum;
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
	int rowSums[n];
	int** matrix = new int* [n];

	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = rand() % 50;
		}
	}

	cout << "Matrix:\n";
	printMatrix(matrix, n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++)
		{
			calculateRowSums(matrix, n, rowSums);
		}
	}

	cout << "Row sums: ";
	for (int i = 1; i < n; i++) {
		cout << rowSums[i] << " ";
	}
	cout << endl;


	for (int i = 0; i < n; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;

	return 0;
}