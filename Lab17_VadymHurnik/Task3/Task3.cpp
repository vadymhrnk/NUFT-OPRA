#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

void calculateColumnAverages(int** array, int size) {
	for (int j = 0; j < size; j++) {
		int sum = 0;
		int numElements = 0;
		for (int i = 0; i < size && i <= j && i < (size - j); i++) {
			sum += array[i][j];
			numElements++;
		}
		double average = static_cast<double>(sum) / numElements;
		cout << "Average of column " << j + 1 << ": " << average << std::endl;
	}
}

int** generateRandomArray(int size) {
	int** array = new int* [size];
	srand(time(0));

	for (int i = 0; i < size; i++) {
		array[i] = new int[size];
		for (int j = 0; j < size; j++) {
			array[i][j] = rand() % 30;
		}
	}

	return array;
}

void printArray(int** array, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
}

void deleteArray(int** array, int size) {
	for (int i = 0; i < size; i++) {
		delete[] array[i];
	}
	delete[] array;
}

int main() {
	int size;
	cout << "Enter the size of the array: ";
	cin >> size;

	int** array = generateRandomArray(size);

	cout << "Generated array:\n";
	printArray(array, size);

	cout << "New array:\n";
	printArray(array, size);

	calculateColumnAverages(array, size);

	deleteArray(array, size);

	return 0;
}
