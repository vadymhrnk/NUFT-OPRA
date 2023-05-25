#include <iostream>
#include <fstream>
#include <StaticLib.h>
#include <DynamicLib.h>

using namespace std;

int main() {
    StaticLibrary::StaticLib lib;
    srand(time(0));
    const int n = 5;
    int rowSums[n];
    int** matrix = new int* [n];

    string inputFileName;
    cout << "Enter the input file name: ";
    cin >> inputFileName;

    ifstream inputFile(inputFileName);
    if (!inputFile) {
        cout << "Input file does not exist. Creating a new file." << endl;
        inputFile.close();

        ofstream createInputFile(inputFileName);
        if (!createInputFile) {
            cout << "Error creating file: " << inputFileName << endl;
            return 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int value = rand() % 50;
                createInputFile << value << " ";
            }
            createInputFile << endl;
        }
        createInputFile.close();
    }
    else {
        inputFile.close();
    }

    ifstream inputFile2(inputFileName);
    if (!inputFile2) {
        cout << "Error opening file: " << inputFileName << endl;
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            inputFile2 >> matrix[i][j];
        }
    }
    inputFile2.close();

    cout << "Matrix:\n";
    lib.printMatrix(matrix, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++)
        {
            calculateRowSums(matrix, n, rowSums);
        }
    }

    string outputFileName;
    cout << "Enter the output file name for row sums: ";
    cin >> outputFileName;

    ofstream outputFile(outputFileName);
    if (!outputFile) {
        cout << "Error creating file: " << outputFileName << endl;
        return 1;
    }

    calculateRowSums(matrix, n, rowSums);

    cout << "Row sums: ";
    for (int i = 1; i < n; i++) {
        cout << rowSums[i] << " ";
        outputFile << rowSums[i] << " ";
    }
    cout << endl;
    outputFile.close();

    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
