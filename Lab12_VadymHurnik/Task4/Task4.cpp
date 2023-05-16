#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h> 
using namespace std;

const int MAX_SIZE = 100;

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

    for (int i = 0; i < size; i++) {
        int tempArr[MAX_SIZE];
        for (int j = 0; j < size; j++) {
            tempArr[j] = matrix[j][i];
        }
        maxArr[i] = findMax(tempArr, size);
    }

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << endl << "Max elements for each column:" << endl;
    for (int i = 0; i < size; i++) {
        SetConsoleTextAttribute(hConsole, i + 1);
        cout << maxArr[i] << "\t";
    }
    SetConsoleTextAttribute(hConsole, 7);

    return 0;
}
