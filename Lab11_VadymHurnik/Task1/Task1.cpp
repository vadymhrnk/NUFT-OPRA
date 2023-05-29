#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void bubbleSort(int arr[], int size) {
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

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void generateArrays(int arr1[],int arr2[], const int SIZE) {
    for (int i = 0; i < SIZE; i++) {
        arr1[i] = rand() % 100 - 50;
        arr2[i] = rand() % 100 - 50;
    }
}

int main() {
    srand(time(NULL));
    const int SIZE = 10;
    int arr1[SIZE];
    int arr2[SIZE];

    generateArrays(arr1, arr2, SIZE);

    cout << "Array 1 (unsorted): ";
    printArray(arr1, SIZE);
    cout << "Array 2 (unsorted): ";
    printArray(arr2, SIZE);

    bubbleSort(arr1, SIZE);
    bubbleSort(arr2, SIZE);

    cout << "Array 1 (sorted): ";
    printArray(arr1, SIZE);
    cout << "Array 2 (sorted): ";
    printArray(arr2, SIZE);

    return 0;
}