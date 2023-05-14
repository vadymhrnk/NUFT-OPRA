#include <iostream>

using namespace std;

void countPositiveAndNegative(int *arr, int n, int &positiveCount, int &negativeCount) {
    positiveCount = 0;
    negativeCount = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            positiveCount++;
        } else if (arr[i] < 0) {
            negativeCount++;
        }
    }
}

int main() {
    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    int positiveCount, negativeCount;

    countPositiveAndNegative(arr, n, positiveCount, negativeCount);

    cout << "Number of positive elements: " << positiveCount << endl;
    cout << "Number of negative elements: " << negativeCount << endl;

    delete[] arr;

    return 0;
}
