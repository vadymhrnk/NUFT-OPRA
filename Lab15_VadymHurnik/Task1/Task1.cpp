#include <iostream>
#include <string>
#include <stdio.h>
#include <ctime>
#include<StaticLib.h>
#include<DynamicLib.h>

using namespace std;

void createTextMatrixFile(const char* filename) {
	int size;
	cout << "Enter size of square matrix: ";
	cin >> size;

	FILE* file;

	if (fopen_s(&file, filename, "w") == 0) {
		fprintf(file, "%d\n", size);
		srand(time(0));

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				int value = rand() % 101 - 50;
				fprintf(file, "%d ", value);
			}
			fprintf(file, "\n");
		}
		fclose(file);
		cout << "Text matrix file created successfully." << endl;
	}
	else {
		cout << "Error creating text matrix file." << endl;
	}
}

void createTextStringsFile(const char* filename) {
	int numStrings;
	cout << "Enter the number of strings: ";
	cin >> numStrings;

	FILE* file;
	if (fopen_s(&file, filename, "w") == 0) {
		cin.ignore();
		for (int i = 0; i < numStrings; i++) {
			string str;
			cout << "Enter string " << (i + 1) << ": ";
			getline(cin, str);
			fprintf(file, "%s\n", str.c_str());
		}
		fclose(file);
		cout << "Text strings file created successfully." << endl;
	}
	else {
		cout << "Error creating text strings file." << endl;
	}
}

void createBinaryArrayFile(const char* filename) {
	int size;
	cout << "Enter the size of the array: ";
	cin >> size;

	FILE* file;
	if (fopen_s(&file, filename, "wb") == 0) {
		fwrite(&size, sizeof(int), 1, file);
		srand(time(0));

		for (int i = 0; i < size; i++) {
			int value = rand() % 101 - 50;
			fwrite(&value, sizeof(int), 1, file);
		}
		fclose(file);
		cout << "Binary array file created successfully." << endl;
	}
	else {
		cout << "Error creating binary array file." << endl;
	}
}

void createBinaryColumnMatrixFile(const char* filename) {
	int size;
	cout << "Enter size of square matrix: ";
	cin >> size;

	FILE* file;
	if (fopen_s(&file, filename, "wb") == 0) {
		fwrite(&size, sizeof(int), 1, file);
		fwrite(&size, sizeof(int), 1, file);
		srand(time(0));

		for (int j = 0; j < size; j++) {
			for (int i = 0; i < size; i++) {
				int value = rand() % 101 - 50;
				fwrite(&value, sizeof(int), 1, file);
			}
		}
		fclose(file);
		cout << "Binary column matrix file created successfully." << endl;
	}
	else {
		cout << "Error creating binary column matrix file." << endl;
	}
}

int main() {
	const int MAX_FILENAME_LENGTH = 100;
	char textMatrixFilename[MAX_FILENAME_LENGTH];
	char textStringsFilename[MAX_FILENAME_LENGTH];
	char binaryMatrixFilename[MAX_FILENAME_LENGTH];
	char binaryColumnMatrixFilename[MAX_FILENAME_LENGTH];
	cout << "Enter the name of the text matrix file: ";
	cin.getline(textMatrixFilename, MAX_FILENAME_LENGTH);

	cout << "Enter the name of the text strings file: ";
	cin.getline(textStringsFilename, MAX_FILENAME_LENGTH);

	cout << "Enter the name of the binary matrix file: ";
	cin.getline(binaryMatrixFilename, MAX_FILENAME_LENGTH);

	cout << "Enter the name of the binary column matrix file: ";
	cin.getline(binaryColumnMatrixFilename, MAX_FILENAME_LENGTH);
	system("pause");
	system("cls");

	cout << "Creating text matrix file." << endl;
	createTextMatrixFile(textMatrixFilename);
	system("pause");
	system("cls");
	cout << "Creating text string file." << endl;
	createTextStringsFile(textStringsFilename);
	system("pause");
	system("cls");
	cout << "Creating binary matrix file." << endl;
	createBinaryArrayFile(binaryMatrixFilename);
	system("pause");
	system("cls");
	cout << "Creating binary column matrix file." << endl;
	createBinaryColumnMatrixFile(binaryColumnMatrixFilename);

	return 0;
}