#pragma once
#include <string>

using namespace std;

const int ROWS = 3;
const int COLS = 3;
const int MAX_SIZE = 10;

namespace StaticLibrary
{
    class StaticLib
    {
    public:
        void printArray(int arr[], int size);
        void printMatrix(int** arr, int size);
        bool isPalindrome(int arr[], int n);
        void addComma(string& str);
        void fillMatrix(int arr[ROWS][COLS]);
        void printMatrix(int arr[ROWS][COLS]);
        void replaceBrackets(string& str);
        void generateMatrix(int matrix[][MAX_SIZE], int size);
        void printMatrix(int matrix[][MAX_SIZE], int size);    
    };
}