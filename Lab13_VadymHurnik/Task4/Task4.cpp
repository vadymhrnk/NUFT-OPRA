#include <iostream>
using namespace std;

void sum_below_main_diag(int** matrix, int n, int* result) {
    for (int i = 0; i < n; i++) {
        result[i] = 0;
        for (int j = i + 1; j < n; j++) {
            if (matrix[i][j] > 0) {
                result[i] += matrix[i][j];
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the matrix: ";
    cin >> n;

    // Allocate memory for the matrix
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }

    // Read the matrix elements
    cout << "Enter the matrix elements:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // Calculate the sums of positive elements below the main diagonal
    int* result = new int[n];
    sum_below_main_diag(matrix, n, result);

    // Print the result
    cout << "Sums of positive elements below the main diagonal:\n";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    // Free memory
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] result;

    return 0;
}
