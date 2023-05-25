#include <iostream>
#include <fstream>
#include <StaticLib.h>
#include <DynamicLib.h>

using namespace std;

int main()
{
    StaticLibrary::StaticLib lib;

    int size;
    cout << "Enter the size of the matrix: ";
    cin >> size;

    int matrix[MAX_SIZE][MAX_SIZE];
   lib.generateMatrix(matrix, size);

    cout << "Original matrix:" << endl;
    lib.printMatrix(matrix, size);

    string originalFileName, resultFileName;
    cout << "Enter the name of the file to store the original matrix: ";
    cin >> originalFileName;
    cout << "Enter the name of the file to store the sorted matrix: ";
    cin >> resultFileName;

    ofstream originalFile(originalFileName);
    if (originalFile.is_open()) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                originalFile << matrix[i][j] << "\t";
            }
            originalFile << endl;
        }
        originalFile.close();
        cout << "Original matrix written to " << originalFileName << endl;
    }
    else {
        cout << "Unable to create/open the file " << originalFileName << endl;
    }

    sortMatrix(matrix, size);

    cout << "Sorted matrix:" << endl;
    lib.printMatrix(matrix, size);

    ofstream resultFile(resultFileName);
    if (resultFile.is_open()) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                resultFile << matrix[i][j] << "\t";
            }
            resultFile << endl;
        }
        resultFile.close();
        cout << "Sorted matrix written to " << resultFileName << endl;
    }
    else {
        cout << "Unable to create/open the file " << resultFileName << endl;
    }

    return 0;
}
