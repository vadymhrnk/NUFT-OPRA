#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int** generateRandomArray(int size) {
	int** array = new int* [size];
	srand(time(0));

	for (int i = 0; i < size; i++) {
		array[i] = new int[size];
		for (int j = 0; j < size; j++) {
			array[i][j] = 0/*rand() % 10*/;
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

	int counter = 1;
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size && j < (size - i); j++)
		{
			array[j][i] = counter++;
		}
	}

	cout << "New array:\n";
	printArray(array, size);

	deleteArray(array, size);

	return 0;
}
