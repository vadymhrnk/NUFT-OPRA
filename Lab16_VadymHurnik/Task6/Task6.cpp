#include <iostream>
#include <fstream>
#include <string>
#include <StaticLib.h>
#include <DynamicLib.h>


using namespace std;

int main() {
    StaticLibrary::StaticLib lib;
    string inputFilename, outputFilename;
    cout << "Enter input filename: ";
    cin >> inputFilename;
    cout << "Enter output filename: ";
    cin >> outputFilename;

    string str1;
    cout << "Enter text: ";
    cin.ignore();
    getline(cin, str1);

    ofstream inputFile(inputFilename);
    if (!inputFile.is_open()) {
        cout << "Input file cannot be created or opened.\n";
        return 0;
    }
    inputFile << str1 << "\n";
    inputFile.close();

    lib.replaceBrackets(str1);

    ofstream outputFile(outputFilename);
    if (!outputFile.is_open()) {
        cout << "Output file cannot be created or opened.\n";
        return 0;
    }
    outputFile << str1 << "\n";
    outputFile.close();

    cout << "Result has been written to the output file.\n";

    return 0;
}