#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void printArray(int** array, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

int* calculateDiagonalSums(int** matrix, int size) {
    int* diagonalSums = new int[size];

    for (int i = 0; i < size; i++) {
        diagonalSums[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (matrix[i][j] > 0) {
                diagonalSums[j - i - 1] += matrix[i][j];
            }
        }
    }

    return diagonalSums;
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main() {
    int size;
    cout << "Enter the size of the square matrix: ";
    cin >> size;

    srand(time(0));

    int** matrix = new int* [size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new int[size];
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 10-5;
        }
    }

    int* diagonalSums = calculateDiagonalSums(matrix, size);

    printArray(matrix, size);
    system("pause");

    clearScreen();

    cout << "Diagonal sums higher than the main diagonal:" << endl;
    for (int i = 0; i < size - 1; i++) {
        cout << diagonalSums[i] << " ";
    }

    for (int i = 0; i < size; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] diagonalSums;

    return 0;
}
