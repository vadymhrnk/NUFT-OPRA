#include <iostream>
#include <stdio.h>
#include <StaticLib.h>
#include <DynamicLib.h>

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

        FILE* inputFile = fopen(("../Task1/" + inputFilename).c_str(), "rb");

        if (inputFile == nullptr) {
            cout << "Error opening input file: " << inputFilename << endl;
            continue;
        }

        int* size = new int;
        fread(size, sizeof(int), 1, inputFile);

        int** matrix = new int* [*size];
        for (int i = 0; i < *size; i++) {
            matrix[i] = new int[*size];
            fread(matrix[i], sizeof(int), *size, inputFile);
        }

        fclose(inputFile);

        lib.printMatrix(matrix, *size);

        sortMatrixPtr(matrix, size);

        cout << "Enter the output file name: ";
        cin >> outputFilename;

        FILE* outputFile = fopen(outputFilename.c_str(), "w");

        if (outputFile == nullptr) {
            cout << "Error opening output file: " << outputFilename << endl;
            continue;
        }

        for (int i = 0; i < *size; i++) {
            for (int j = 0; j < *size; j++) {
                fprintf(outputFile, "%d ", matrix[i][j]);
            }
            fprintf(outputFile, "\n");
        }

        fclose(outputFile);

        lib.printMatrix(matrix, *size);

        cout << "Matrix sorted and written to file: " << outputFilename << endl;

        for (int i = 0; i < *size; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
        delete size;
    }

    return 0;
}