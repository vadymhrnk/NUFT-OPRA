#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void display_matrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void generate_matrix(int** matrix, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

void shell_sort(int** matrix, int n) {
    int gap, i, j, temp;
    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            for (j = i - gap; j >= gap && matrix[j][i - j] != matrix[j + gap][i - j - gap]; j -= gap) {
                if (matrix[j + gap][i - j - gap] > matrix[j][i - j]) {
                    temp = matrix[j + gap][i - j - gap];
                    matrix[j + gap][i - j - gap] = matrix[j][i - j];
                    matrix[j][i - j] = temp;
                }
            }
        }
    }
}

int main() {
    const int n = 5;
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }

    generate_matrix(matrix, n);

    cout << "Matrix before sorting:" << endl;
    display_matrix(matrix, n);

    shell_sort(matrix, n);

    cout << "Matrix after sorting:" << endl;
    display_matrix(matrix, n);

    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
