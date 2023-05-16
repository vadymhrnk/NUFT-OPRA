#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>  

using namespace std;

const int MAX_SIZE = 10;

void generateMatrix(int matrix[][MAX_SIZE], int size)
{
    srand(time(0));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

void printMatrix(int matrix[][MAX_SIZE], int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void sortMatrix(int matrix[][MAX_SIZE], int size)
{
    int temp[MAX_SIZE];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            temp[j] = matrix[i][j];
        }
        for (int j = 0; j < size - 1; j++) {
            for (int k = j + 1; k < size; k++) {
                if (temp[j] < temp[k]) {
                    int t = temp[j];
                    temp[j] = temp[k];
                    temp[k] = t;
                }
            }
        }
        for (int j = 0; j < size; j++) {
            matrix[i][j] = temp[j];
        }
    }
}

int main()
{
    int size;
    cout << "Enter the size of the matrix: ";
    cin >> size;

    int matrix[MAX_SIZE][MAX_SIZE];
    generateMatrix(matrix, size);

    cout << "Original matrix:" << endl;
    printMatrix(matrix, size);

    sortMatrix(matrix, size);

    cout << "Sorted matrix:" << endl;
    printMatrix(matrix, size);

    return 0;
}
