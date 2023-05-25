#include <iostream>
#include <fstream>
#include<StaticLib.h>
#include<DynamicLib.h>

using namespace std;


int main() {
    StaticLibrary::StaticLib lib;
    string inputFileName;
    cout << "Enter the name of the input file: ";
    cin >> inputFileName;

    ofstream inputFile(inputFileName, ios::binary | ios::trunc);
    if (!inputFile) {
        cout << "Failed to create/open input file." << endl;
        return 1;
    }

    int arr[] = { 1, 2, 3, 2, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);

    inputFile.write(reinterpret_cast<char*>(arr), sizeof(arr));
    inputFile.close();

    cout << "Original array: ";
    lib.printArray(arr, n);

    if (lib.isPalindrome(arr, n)) {
        cout << "The array is a palindrome" << endl;
    }
    else {
        cout << "The array is not a palindrome" << endl;
    }

    string outputFileName;
    cout << "Enter the name of the output file: ";
    cin >> outputFileName;

    ofstream outputFile(outputFileName);
    if (!outputFile) {
        cout << "Failed to open output file." << endl;
        return 1;
    }

    for (int i = 0; i < n; i++) {
        outputFile << arr[i] << " ";
    }
    outputFile << endl;

    if (lib.isPalindrome(arr, n)) {
        outputFile << "The array is a palindrome" << endl;
    }
    else {
        outputFile << "The array is not a palindrome" << endl;
    }

    outputFile.close();

    return 0;
}