#include <iostream>
#include "Arrays.h"
#include "Matrices.h"

int main()
{
	Arrays* arrObj = new Arrays;

	cout << "Enter size of array: ";
	cin >> arrObj->size;


	arrObj->generateArray();
	arrObj->sumEven();
	arrObj->removeElementDividedBySeven();
	arrObj->maxElementAndIndex();
	arrObj->firstNegativeThenPositive();
	arrObj->bogoSort();
	system("pause");
	system("cls");

	Matrices* matrixObj = new Matrices;

	cout << "Enter size for square matrix: ";
	cin >> matrixObj->size;

	cout << "Enter rows for 2D matrix: ";
	cin >> matrixObj->rows;

	cout << "Enter columns for 2D matrix: ";
	cin >> matrixObj->cols;

	cout << "Enter depth for 3D matrix: ";
	cin >> matrixObj->depth;

	cout << endl << "Square matrix:" << endl;
	matrixObj->generateSquareMatrix();
	cout << endl << "2D matrix:" << endl;
	matrixObj->generate2dMatrix();
	cout << endl << "3D matrix:" << endl;
	matrixObj->generate3dMatrix();

	matrixObj->countPositiveElements();
	matrixObj->countNonZeroElements();
	matrixObj->maxElementsDiagonal();
	matrixObj->maxElementIVQuarter();
	cout << endl << "Sorted matrix:" << endl;
	matrixObj->sortDiagonalsBelowMainDiagonal();
}