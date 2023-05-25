#include <iostream>
#include <fstream>
#include <string>
#include <StaticLib.h>
#include <DynamicLib.h>

using namespace std;

int main() {
	StaticLibrary::StaticLib lib;

	string inputFileName;
	cout << "Enter the name of the input file: ";
	cin >> inputFileName;

	ofstream inputFile(inputFileName);
	if (!inputFile) {
		cout << "Failed to create/open input file." << endl;
		return 1;
	}

	string str;
	cin.ignore();
	cout << "Enter a string: ";
	getline(cin, str);

	inputFile << str << endl;
	inputFile.close();

	cout << "Original string: " << str << endl;

	lib.addComma(str);

	cout << "Modified string: " << str << endl;

	string outputFileName;
	cout << "Enter the name of the output file: ";
	cin >> outputFileName;

	ofstream outputFile(outputFileName);
	if (!outputFile) {
		cout << "Failed to create/open output file." << endl;
		return 1;
	}

	outputFile << str << endl;

	outputFile.close();

	return 0;
}
