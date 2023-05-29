#include <iostream>
#include <stdio.h>
#include <StaticLib.h>
#include <DynamicLib.h>

using namespace std;

int** readMatrixFromFile(const string& filename, int& size) {
    FILE* file = fopen(filename.c_str(), "r");
    int** matrix = nullptr;

    if (file != nullptr) {
        fscanf(file, "%d", &size);

        matrix = new int* [size];
        for (int i = 0; i < size; i++) {
            matrix[i] = new int[size];
            for (int j = 0; j < size; j++) {
                fscanf(file, "%d", &matrix[i][j]);
            }
        }

        fclose(file);
    }
    else {
        cout << "Error opening file: " << filename << endl;
    }

    return matrix;
}

void writeRowSumsToFile(const string& filename, int* rowSums, int size) {
    FILE* file = fopen(filename.c_str(), "w");

    if (file != nullptr) {
        for (int i = 0; i < size; i++) {
            fprintf(file, "%d\n", rowSums[i]);
        }

        fclose(file);
        cout << "Row sums written to file: " << filename << endl;
    }
    else {
        cout << "Error opening file: " << filename << endl;
    }
}

void deleteMatrix(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void calculateRowSums(int** matrix, int size, int* rowSums) {
    for (int i = 0; i < size; i++) {
        int sum = 0;
        for (int j = 0; j < size; j++) {
            sum += matrix[i][j];
        }
        rowSums[i] = sum;
    }
}

int main() {
    StaticLibrary::StaticLib lib;
    string inputFilename;
    string outputFilename;
    int size;

    while (true) {
        cout << "Enter the input file name (or 'stop' to exit): ";
        cin >> inputFilename;

        if (inputFilename == "stop") {
            break;
        }

        int** matrix = readMatrixFromFile("..\\Task1\\" + inputFilename, size);
        lib.printMatrix(matrix, size);

        if (matrix != nullptr) {
            cout << "Enter the output file name: ";
            cin >> outputFilename;

            int* rowSums = new int[size];
            calculateRowSums(matrix, size, rowSums);

            cout << "Row sums: ";
            for (int i = 1; i < size; i++) {
                cout << rowSums[i] << " ";
            }
            cout << endl;

            writeRowSumsToFile(outputFilename, rowSums, size);

            delete[] rowSums;
            deleteMatrix(matrix, size);
        }
    }

    return 0;
}
