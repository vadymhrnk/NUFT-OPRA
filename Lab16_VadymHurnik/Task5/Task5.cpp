#include <iostream>
#include <fstream>
#include <StaticLib.h>
#include <DynamicLib.h>

using namespace std;

int main()
{
    StaticLibrary::StaticLib lib;
    int arr[ROWS][COLS];
    lib.fillMatrix(arr);

    string matrixFileName, resultFileName;
    cout << "Enter matrix file name: ";
    cin >> matrixFileName;
    cout << "Enter result file name: ";
    cin >> resultFileName;


    ofstream outputFile(matrixFileName);
    if (outputFile.is_open())
    {
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                outputFile << arr[i][j] << " ";
            }
            outputFile << endl;
        }
        outputFile.close();
    }
    else
    {
        cout << "Failed to create/open the file." << endl;
        return 1;
    }

    ifstream inputFile(matrixFileName);
    if (inputFile.is_open())
    {
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                inputFile >> arr[i][j];
            }
        }
        inputFile.close();
    }
    else
    {
        cout << "Failed to open the file." << endl;
        return 1;
    }

    lib.printMatrix(arr);

    int sum, count;
    sumAndCountNegatives(arr, sum, count);

    ofstream resultFile(resultFileName);
    if (resultFile.is_open())
    {
        resultFile << "Sum of negative elements: " << sum << endl;
        resultFile << "Number of negative elements: " << count << endl;
        resultFile.close();
    }
    else
    {
        cout << "Failed to create/open the file." << endl;
        return 1;
    }

    cout << "Sum of negative elements: " << sum << endl;
    cout << "Number of negative elements: " << count << endl;

    return 0;
}
