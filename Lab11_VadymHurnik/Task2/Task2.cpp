#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void shellSort(int** matrix, int rows, int columns) {
    for (int col = 0; col < columns; col++) {
        for (int gap = rows / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < rows; i++) {
                int temp = matrix[i][col];
                int j;
                for (j = i; j >= gap && matrix[j - gap][col] < temp; j -= gap) {
                    matrix[j][col] = matrix[j - gap][col];
                }
                matrix[j][col] = temp;
            }
        }
    }
}

void printMatrix(int** arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void sortMatrix(int** matrix,int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < i; j++) {
            shellSort(matrix, j, i);
        }
    }

}

int** generateMatrix(int size) {
    int** matrix = new int* [size];

    for (int i = 0; i < size; i++) {
        matrix[i] = new int[size];
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 50;
        }
    }

    return matrix;
}

void deleteMatrix(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

}

int main() {
    srand(time(0));
    const int n = 5;
    int** matrix = generateMatrix(n);

    cout << "Initial:\n";
    printMatrix(matrix, n);

    sortMatrix(matrix, n);

    cout << "Sorted:\n";
    printMatrix(matrix, n);

    deleteMatrix(matrix, n);

    return 0;
}
