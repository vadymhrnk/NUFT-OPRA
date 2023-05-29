#include <iostream>
#include <stdio.h>
#include<StaticLib.h>
#include<DynamicLib.h>

using namespace std;

int main() {
    StaticLibrary::StaticLib lib;
    string inputFilename;
    string outputFilename;

    while (true) {
        cout << "Enter the input text file name (or 'stop' to exit): ";
        cin >> inputFilename;

        if (inputFilename == "stop") {
            break;
        }

        FILE* inputFile = fopen(("../Task1/" + inputFilename).c_str(), "r");

        if (inputFile == nullptr) {
            cout << "Error opening input file: " << inputFilename << endl;
            continue;
        }

        cout << "Enter the output file name: ";
        cin >> outputFilename;

        FILE* outputFile = fopen(outputFilename.c_str(), "w");

        if (outputFile == nullptr) {
            cout << "Error opening output file: " << outputFilename << endl;
            continue;
        }

        char line[256];
        while (fgets(line, sizeof(line), inputFile)) {
            line[strcspn(line, "\n")] = '\0';
            cout << "Original string: " << line << endl;
            lib.addComma(line);
            cout << "Modified string: " << line << endl;
            fprintf(outputFile, "%s\n", line);
        }

        fclose(inputFile);
        fclose(outputFile);

        cout << "Result written to file: " << outputFilename << endl;
    }

    return 0;
}