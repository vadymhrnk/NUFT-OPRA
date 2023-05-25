#include <iostream>
#include <fstream>
#include <StaticLib.h>
#include <DynamicLib.h>

using namespace std;

int main() {
    srand(time(NULL));

    const int size1 = 5, size2 = 7, size3 = 10;

    int arr1[size1], arr2[size2], arr3[size3];
    for (int i = 0; i < size1; i++) {
        arr1[i] = rand() % 100;
    }
    for (int i = 0; i < size2; i++) {
        arr2[i] = rand() % 100;
    }
    for (int i = 0; i < size3; i++) {
        arr3[i] = rand() % 100;
    }

    string fileName, resultFileName;
    cout << "Enter a name for the file: ";
    cin >> fileName;

    ofstream inputFile(fileName);
    if (inputFile.is_open()) {
        for (int i = 0; i < size1; i++) {
            inputFile << arr1[i] << " ";
        }
        inputFile << endl;

        for (int i = 0; i < size2; i++) {
            inputFile << arr2[i] << " ";
        }
        inputFile << endl;

        for (int i = 0; i < size3; i++) {
            inputFile << arr3[i] << " ";
        }
        inputFile.close();
        cout << "Arrays are written to " << fileName << endl;

        cout << "Enter a name for the result file: ";
        cin >> resultFileName;

        ofstream resultsFile(resultFileName);
        if (resultsFile.is_open()) {
            resultsFile << "Average value of odd elements for each array:\n";

            resultsFile << "First array:\n";
            resultsFile << "Average value: " << averageOdd(arr1, size1) << endl;

            resultsFile << "\nSecond array:\n";
            resultsFile << "Average value: " << averageOdd(arr2, size2) << endl;

            resultsFile << "\nThird array:\n";
            resultsFile << "Average value: " << averageOdd(arr3, size3) << endl;

            resultsFile.close();
            cout << "Results are written to " << resultFileName << endl;
        }
        else {
            cout << "Failed to create the result file." << endl;
            return 1;
        }
    }
    else {
        cout << "Failed to create the input file." << endl;
        return 1;
    }

    return 0;
}
