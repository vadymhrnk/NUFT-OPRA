#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

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

int main() {
    srand(time(NULL));

    const int size1 = 5, size2 = 7, size3 = 10;

    int arr1[size1], arr2[size2], arr3[size3];
    for (int i = 0; i < size1; i++) {
        arr1[i] = rand() % 100;
    }
    for (int i = 0; i < size2; i++) {
        arr2[i] = rand() % 100;
    }
    for (int i = 0; i < size3; i++) {
        arr3[i] = rand() % 100;
    }

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 11);
    cout << "First array:\n";
    for (int i = 0; i < size1; i++) {
        cout << arr1[i] << " ";
    }
    cout << "\nAverage value of odd elements: " << averageOdd(arr1, size1) << endl;

    SetConsoleTextAttribute(hConsole, 12);
    cout << "\nSecond array:\n";
    for (int i = 0; i < size2; i++) {
        cout << arr2[i] << " ";
    }
    cout << "\nAverage value of odd elements: " << averageOdd(arr2, size2) << endl;

    SetConsoleTextAttribute(hConsole, 13);
    cout << "\nThird array:\n";
    for (int i = 0; i < size3; i++) {
        cout << arr3[i] << " ";
    }
    cout << "\nAverage value of odd elements: " << averageOdd(arr3, size3) << endl;

    SetConsoleTextAttribute(hConsole, 7);

    return 0;
}
