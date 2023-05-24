#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int* generateRandomArray(int size) {
    int* array = new int[size];
    srand(time(0));  // Seed the random number generator with current time

    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;  // Generate random numbers between 0 and 99
    }

    return array;
}

void printArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void findMinimumElement(int* array, int size) {
    int minElement = array[0];
    int count = 1;

    for (int i = 1; i < size; i++) {
        if (array[i] < minElement) {
            minElement = array[i];
            count = 1;
        }
        else if (array[i] == minElement) {
            count++;
        }
    }

    cout << "\033[1;32mMinimum element: " << minElement << "\033[0m" << endl;
    cout << "\033[1;34mNumber of elements equal to the minimum: " << count << "\033[0m" << endl;
}

void deleteArray(int* array) {
    delete[] array;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int* array = generateRandomArray(size);

    cout << "Generated array: ";
    printArray(array, size);

    findMinimumElement(array, size);

    deleteArray(array);

    return 0;
}
