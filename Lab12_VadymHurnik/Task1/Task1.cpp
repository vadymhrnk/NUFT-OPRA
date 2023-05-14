#include <iostream>
using namespace std;

bool isPalindrome(int arr[], int n) {
    int i = 0, j = n - 1;

    while (i < j) {
        if (arr[i] != arr[j]) {
            return false;
        }
        i++;
        j--;
    }

    return true;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = { 1, 2, 3, 2, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    if (isPalindrome(arr, n)) {
        cout << "The array is a palindrome" << endl;
    }
    else {
        cout << "The array is not a palindrome" << endl;
    }

    return 0;
}
