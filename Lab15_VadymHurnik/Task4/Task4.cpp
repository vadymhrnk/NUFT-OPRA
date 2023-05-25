#include <iostream>
#include <fstream>
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

		int size;
		inputFile.read(reinterpret_cast<char*>(&size), sizeof(int));

		int* arr = new int[size];
		inputFile.read(reinterpret_cast<char*>(arr), size * sizeof(int));

		inputFile.close();

		lib.printArray(arr, size);

		double result = averageOdd(arr, size);

		cout << "Average odd: " << result << endl;

		cout << "Enter the output file name: ";
		cin >> outputFilename;

		ofstream outputFile(outputFilename);

		if (!outputFile.is_open()) {
			cout << "Error opening output file: " << outputFilename << endl;
			continue;
		}

		outputFile << result << endl;

		outputFile.close();

		cout << "Result written to file: " << outputFilename << endl;

		delete[] arr;
	}

	return 0;
}
