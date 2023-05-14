#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void bubble_sort(int arr[], int size) {
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

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    srand(time(NULL));
    const int SIZE = 10;
    int arr1[SIZE];
    int arr2[SIZE];
    for (int i = 0; i < SIZE; i++) {
        arr1[i] = rand() % 100 - 50;
        arr2[i] = rand() % 100 - 50;
    }

    cout << "Array 1 (unsorted): ";
    print_array(arr1, SIZE);
    cout << "Array 2 (unsorted): ";
    print_array(arr2, SIZE);

    bubble_sort(arr1, SIZE);
    bubble_sort(arr2, SIZE);

    cout << "Array 1 (sorted): ";
    print_array(arr1, SIZE);
    cout << "Array 2 (sorted): ";
    print_array(arr2, SIZE);

    return 0;
}