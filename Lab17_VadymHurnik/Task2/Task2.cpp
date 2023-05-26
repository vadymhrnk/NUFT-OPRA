#include <iostream>
#include <algorithm>

using namespace std;

int* generateRandomArray(int size) {
    int* array = new int[size];
    srand(time(0));

    for (int i = 0; i < size; i++) {
        array[i] = rand() % 10 - 5;
    }

    return array;
}

void printArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void sortArray(int* array, int size) {
    int* zeros = new int[size];
    int* positives = new int[size];
    int* negatives = new int[size];

    int zeroCount = 0;
    int positiveCount = 0;
    int negativeCount = 0;

    for (int i = 0; i < size; i++) {
        if (array[i] == 0)
            zeros[zeroCount++] = array[i];
        else if (array[i] > 0)
            positives[positiveCount++] = array[i];
        else
            negatives[negativeCount++] = array[i];
    }

    sort(zeros, zeros + zeroCount);
    sort(positives, positives + positiveCount);
    sort(negatives, negatives + negativeCount);

    int index = 0;

    for (int i = 0; i < zeroCount; i++) {
        array[index++] = zeros[i];
    }

    for (int i = 0; i < positiveCount; i++) {
        array[index++] = positives[i];
    }

    for (int i = 0; i < negativeCount; i++) {
        array[index++] = negatives[i];
    }

    delete[] zeros;
    delete[] positives;
    delete[] negatives;
}

void deleteArray(int* array) {
    delete[] array;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int* array = generateRandomArray(size);

    cout << "\033[1;32mGenerated array: ";
    printArray(array, size);
    cout << "\033[0m";

    sortArray(array, size);

    cout << "\033[1;34mSorted array: ";
    printArray(array, size);
    cout << "\033[0m";

    deleteArray(array);

    return 0;
}
