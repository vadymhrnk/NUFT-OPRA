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

        int size;
        fread(&size, sizeof(int), 1, inputFile);

        int* arr = new int[size];
        fread(arr, sizeof(int), size, inputFile);

        fclose(inputFile);

        lib.printArray(arr, size);

        double result = averageOdd(arr, size);

        cout << "Average odd: " << result << endl;

        cout << "Enter the output file name: ";
        cin >> outputFilename;

        FILE* outputFile = fopen(outputFilename.c_str(), "w");

        if (outputFile == nullptr) {
            cout << "Error opening output file: " << outputFilename << endl;
            continue;
        }

        fprintf(outputFile, "%f\n", result);

        fclose(outputFile);

        cout << "Result written to file: " << outputFilename << endl;

        delete[] arr;
    }

    return 0;
}