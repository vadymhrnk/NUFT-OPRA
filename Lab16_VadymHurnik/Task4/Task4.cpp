#include <iostream>
#include <fstream>
#include <StaticLib.h>
#include <DynamicLib.h>

using namespace std;

int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int maxArr[MAX_SIZE];
    int size;

    cout << "Enter the size of the matrix: ";
    cin >> size;

    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 100;
        }
    }

    cout << "Generated Matrix:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    string matrixFileName, resultFileName;
    cout << "Enter a name for the matrix file: ";
    cin >> matrixFileName;
    cout << "Enter a name for the result file: ";
    cin >> resultFileName;

    ofstream inputFile(matrixFileName);
    if (inputFile.is_open()) {
        inputFile << size << endl;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                inputFile << matrix[i][j] << " ";
            }
            inputFile << endl;
        }
        inputFile.close();
        cout << "Matrix data is written to " << matrixFileName << endl;
    }
    else {
        cout << "Failed to create the matrix file." << endl;
        return 1;
    }

    for (int i = 0; i < size; i++) {
        int tempArr[MAX_SIZE];
        for (int j = 0; j < size; j++) {
            tempArr[j] = matrix[j][i];
        }
        maxArr[i] = findMax(tempArr, size);
    }

    cout << endl << "Max elements for each column:" << endl;
    for (int i = 0; i < size; i++) {
        cout << maxArr[i] << "\t";
    }

    ofstream resultFile(resultFileName);
    if (resultFile.is_open()) {
        resultFile << "Max elements for each column:" << endl;
        for (int i = 0; i < size; i++) {
            resultFile << maxArr[i] << "\t";
        }
        resultFile.close();
        cout << endl << "Max elements are written to " << resultFileName << endl;
    }
    else {
        cout << endl << "Failed to create the result file." << endl;
        return 1;
    }

    return 0;
}
