#include <iostream>
#include <cstdlib>
using namespace std;

int** createMatrix(int rows, int cols)
{
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 21 - 10;
        }
    }
    return matrix;
}

void displayMatrix(int** matrix, int rows, int cols)
{
    cout << "Matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

int* findMaxPositiveElements(int** matrix, int rows, int cols)
{
    int* max_elements = new int[rows];
    for (int i = 0; i < rows; i++) {
        max_elements[i] = -1;
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] > 0 && (max_elements[i] == -1 || matrix[i][j] > max_elements[i])) {
                max_elements[i] = matrix[i][j];
            }
        }
    }
    return max_elements;
}

void displayMaxPositiveElements(int* max_elements, int rows)
{
    cout << "Max positive elements of every row:\n";
    for (int i = 0; i < rows; i++) {
        if (max_elements[i] == -1) {
            cout << "In row " << i + 1 << " no positive elements\n";
        }
        else {
            cout << "Max positive element in row " << i + 1 << " = " << max_elements[i] << endl;
        }
    }
}

int* createPositiveElementsArray(int* max_elements, int rows)
{
    int* positive_elements = new int[rows];
    int j = 0;
    for (int i = 0; i < rows; i++) {
        if (max_elements[i] > 0) {
            positive_elements[j] = max_elements[i];
            j++;
        }
    }
    return positive_elements;
}

void displayPositiveElementsArray(int* positive_elements, int size)
{
    if (size == 0) {
        cout << "There are no positive elements in the matrix\n";
    }
    else {
        cout << "Array of max positive elements:\n";
        for (int i = 0; i < size; i++) {
            cout << positive_elements[i] << "\t";
        }
        cout << endl;
    }
}

void deleteMatrix(int** matrix, int rows)
{
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void deleteArrays(int* max_elements, int* positive_elements)
{
    delete[] max_elements;
    delete[] positive_elements;
}

int main()
{
    int rows, cols;
    cout << "Enter rows: ";
    cin >> rows;
    cout << "Enter columns: ";
    cin >> cols;

    int** matrix = createMatrix(rows, cols);

    displayMatrix(matrix, rows, cols);

    int* max_elements = findMaxPositiveElements(matrix, rows, cols);

    displayMaxPositiveElements(max_elements, rows);

    int* positive_elements = createPositiveElementsArray(max_elements, rows);

    displayPositiveElementsArray(positive_elements, rows);

    deleteMatrix(matrix, rows);
    deleteArrays(max_elements, positive_elements);

    return 0;
}
