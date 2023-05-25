#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include<StaticLib.h>
#include<DynamicLib.h>

using namespace std;

int main() {
	StaticLibrary::StaticLib lib;
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

		lib.printMatrix(matrix, size);

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

		lib.printMatrix(matrix, size);

		cout << "Matrix sorted and written to file: " << outputFilename << endl;

		for (int i = 0; i < *size; i++) {
			delete[] matrix[i];
		}
		delete[] matrix;
		delete size;
	}

	return 0;
}
