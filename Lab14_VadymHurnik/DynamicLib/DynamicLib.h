#pragma once
#include "../StaticLib/StaticLib.h"

#ifdef DYNAMICLIB_EXPORTS
#define DYNAMICLIB_API __declspec(dllexport)
#else
#define DYNAMICLIB_API __declspec(dllimport)
#endif

extern "C" DYNAMICLIB_API void bubbleSort(int arr[], int size);
extern "C" DYNAMICLIB_API void shellSort(int** matrix, int rows, int columns);
extern "C" DYNAMICLIB_API double averageOdd(int arr[], int size);
extern "C" DYNAMICLIB_API int findMax(int arr[], int size);
extern "C" DYNAMICLIB_API void sumAndCountNegatives(int arr[ROWS][COLS], int& sum, int& count);
extern "C" DYNAMICLIB_API void sortMatrix(int matrix[][MAX_SIZE], int size);
extern "C" DYNAMICLIB_API void calculateRowSums(int** matrix, int rowCount, int* rowSums);