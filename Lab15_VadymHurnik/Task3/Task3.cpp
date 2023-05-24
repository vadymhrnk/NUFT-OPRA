#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

void printMatrix(int** arr, int* size) {
	for (int i = 0; i < *size; i++) {
		for (int j = 0; j < *size; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

void sortMatrix(int** matrix, int* size) {
	int** temp = new int* [*size];
	for (int i = 0; i < *size; i++) {
		temp[i] = new int[*size];
		for (int j = 0; j < *size; j++) {
			temp[i][j] = matrix[i][j];
		}
		sort(temp[i], temp[i] + *size, greater<int>());
	}
	for (int i = 0; i < *size; i++) {
		for (int j = 0; j < *size; j++) {
			matrix[i][j] = temp[i][j];
		}
		delete[] temp[i];
	}
	delete[] temp;
}

int main() {
	string inputFilename;
	string outputFilename;

	while (true) {
		cout << "Enter the input binary file name (or 'stop' to exit): ";
		cin >> inputFilename;

		if (inputFilename == "stop") {
			break;
		}

		ifstream inputFile("..\\Task1\\" + inputFilename, ios::binary);

		if (!inputFile.is_open()) {
			cout << "Error opening input file: " << inputFilename << endl;
			continue;
		}

		int* size = new int;
		inputFile.read(reinterpret_cast<char*>(size), sizeof(int));

		int** matrix = new int* [*size];
		for (int i = 0; i < *size; i++) {
			matrix[i] = new int[*size];
			inputFile.read(reinterpret_cast<char*>(matrix[i]), *size * sizeof(int));
		}

		inputFile.close();

		printMatrix(matrix, size);

		sortMatrix(matrix, size);


		cout << "Enter the output file name: ";
		cin >> outputFilename;

		ofstream outputFile(outputFilename);

		if (!outputFile.is_open()) {
			cout << "Error opening output file: " << outputFilename << endl;
			continue;
		}

		for (int i = 0; i < *size; i++) {
			for (int j = 0; j < *size; j++) {
				outputFile << matrix[i][j] << " ";
			}
			outputFile << endl;
		}

		outputFile.close();

		printMatrix(matrix, size);

		cout << "Matrix sorted and written to file: " << outputFilename << endl;

		for (int i = 0; i < *size; i++) {
			delete[] matrix[i];
		}
		delete[] matrix;
		delete size;
	}

	return 0;
}
