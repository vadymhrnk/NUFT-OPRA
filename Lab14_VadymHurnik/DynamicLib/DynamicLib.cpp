#include "pch.h" 
#include "DynamicLib.h"

void bubbleSort(int arr[], int size)
{
    for (int i = 1; i < size; i += 2) {
        for (int j = 1; j < size - i; j += 2) {
            if (arr[j] > arr[j + 2]) {
                int temp = arr[j];
                arr[j] = arr[j + 2];
                arr[j + 2] = temp;
            }
        }
    }
}

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

double averageOdd(int arr[], int size) {
    int count = 0;
    double sum = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 != 0) {
            sum += arr[i];
            count++;
        }
    }
    if (count == 0) {
        return 0;
    }
    else {
        return sum / count;
    }
}

int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void sumAndCountNegatives(int arr[ROWS][COLS], int& sum, int& count)
{
    sum = 0;
    count = 0;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (arr[i][j] < 0)
            {
                sum += arr[i][j];
                count++;
            }
        }
    }
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

void calculateRowSums(int** matrix, int rowCount, int* rowSums) {
    for (int i = 0; i < rowCount; i++)
    {
        int sum = 0;
        for (int j = 0; j < i; j++)
        {
            sum += matrix[i][j];
        }
        rowSums[i] = sum;
    }
}
