#include <iostream>
#include <fstream>

using namespace std;

void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

double averageOdd(int arr[], int size) {
	int count = 0;
	double sum = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] % 2 != 0) {
			sum += arr[i];
			count++;
		}
	}
	if (count == 0) {
		return 0;
	}
	else {
		return sum / count;
	}
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

		int size;
		inputFile.read(reinterpret_cast<char*>(&size), sizeof(int));

		int* arr = new int[size];
		inputFile.read(reinterpret_cast<char*>(arr), size * sizeof(int));

		inputFile.close();

		printArray(arr, size);

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
