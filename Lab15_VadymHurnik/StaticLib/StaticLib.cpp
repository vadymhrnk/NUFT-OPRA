// StaticLib.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "StaticLib.h"
#include <iostream>

// TODO: This is an example of a library function
void fnStaticLib()
{
}

void StaticLibrary::StaticLib::printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void StaticLibrary::StaticLib::printMatrix(int** arr, int size)
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

bool StaticLibrary::StaticLib::isPalindrome(int arr[], int n)
{
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

void StaticLibrary::StaticLib::addComma(string& str)
{
    for (int i = 0; i < str.length(); i++) {
        if (isdigit(str[i]) && i + 1 < str.length() && str[i + 1] == '+') {
            str.insert(i + 1, ",");
            i += 1;
        }
    }
}

void StaticLibrary::StaticLib::fillMatrix(int arr[ROWS][COLS])
{
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            arr[i][j] = rand() % 21 - 10;
        }
    }
}

void StaticLibrary::StaticLib::printMatrix(int arr[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (arr[i][j] < 0)
            {
                cout << "\033[31m" << arr[i][j] << "\033[0m" << "\t";
            }
            else
            {
                cout << "\033[32m" << arr[i][j] << "\033[0m" << "\t";
            }
        }
        cout << endl;
    }
}

void StaticLibrary::StaticLib::replaceBrackets(string& str)
{
    for (char& c : str) {
        if (c == '(') {
            c = '[';
        }
        else if (c == ')') {
            c = ']';
        }
    }
}

void StaticLibrary::StaticLib::generateMatrix(int matrix[][MAX_SIZE], int size)
{
    srand(time(0));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

void StaticLibrary::StaticLib::printMatrix(int matrix[][MAX_SIZE], int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void StaticLibrary::StaticLib::printMatrix(int** arr, int* size)
{
    for (int i = 0; i < *size; i++) {
        for (int j = 0; j < *size; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}
