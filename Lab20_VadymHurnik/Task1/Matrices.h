#pragma once
class Matrices
{
public:
	int rows;
	int cols;
	int depth;
	int size;
	Matrices();
	~Matrices();
	void generate2dMatrix();
	void generate3dMatrix();
	void generateSquareMatrix();
	void countPositiveElements();
	void countNonZeroElements();
	void maxElementsDiagonal();
	void maxElementIVQuarter();
	void cocktailSort(int arr[], int n);
	void sortDiagonalsBelowMainDiagonal();
private:
	int matrix[50][50];
	int _3dMatrix[50][50][50];
	int squareMatrix[50][50];
};

Matrices::Matrices()
{
}

Matrices::~Matrices()
{
}

inline void Matrices::generate2dMatrix()
{
	srand(time(0));
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			matrix[i][j] = rand() % 100;
		}
	}

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
}

inline void Matrices::generate3dMatrix()
{
	srand(time(0));
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			for (int k = 0; k < depth; k++) {
				_3dMatrix[i][j][k] = rand() % 100;
			}
		}
	}

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			for (int k = 0; k < depth; k++) {
				cout << _3dMatrix[i][j][k] << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}
}

inline void Matrices::generateSquareMatrix()
{
	srand(time(0));
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			squareMatrix[i][j] = rand() % 100;
		}
	}

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			cout << squareMatrix[i][j] << "\t";
		}
		cout << endl;
	}

}

inline void Matrices::countPositiveElements()
{
	int count = 0;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (matrix[i][j] > 0) {
				count++;
			}
		}
	}
	cout << "countPositiveElements(2D): " << count << endl;
}

inline void Matrices::countNonZeroElements()
{
	int count = 0;

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			for (int k = 0; k < depth; ++k) {
				if (_3dMatrix[i][j][k] != 0) {
					count++;
				}
			}
		}
	}

	cout << "countNonZeroElements(3D): " << count << endl;
}

inline void Matrices::maxElementsDiagonal()
{
	int* maxElements = new int[cols];
	for (int k = 0; k < cols; k++) {
		int maxElement = matrix[0][k];

		for (int i = 0, j = k; i < rows && j < cols; i++, j++) {
			if (matrix[i][j] > maxElement)
				maxElement = matrix[i][j];
		}
		maxElements[k] = maxElement;
	}
	cout << "Max elements of each diagonal(2D): ";
	for (int k = 0; k < cols; k++) {
		cout << maxElements[k] << " ";
	}

	for (int k = 1; k < rows; k++) {
		int maxElement = matrix[k][0];

		for (int i = k, j = 0; i < rows && j < cols; i++, j++) {
			if (matrix[i][j] > maxElement)
				maxElement = matrix[i][j];
		}
		maxElements[k - 1] = maxElement;
	}

	for (int k = 0; k < rows - 1; k++) {
		cout << maxElements[k] << " ";
	}
	cout << endl;
	delete[] maxElements;
}

inline void Matrices::maxElementIVQuarter()
{
	int maxElement = squareMatrix[size / 2][size / 2];

	for (int i = size / 2; i < size; i++) {
		for (int j = size / 2; j < size; j++) {
			if (squareMatrix[i][j] > maxElement) {
				maxElement = squareMatrix[i][j];
			}
		}
	}

	cout << "maxElementIVQuarter(Square): " << maxElement << endl;
}

inline void Matrices::cocktailSort(int arr[], int n) {
	bool swapped = true;
	int start = 0;
	int end = n - 1;

	while (swapped) {
		swapped = false;

		for (int i = start; i < end; ++i) {
			if (arr[i] > arr[i + 1]) {
				std::swap(arr[i], arr[i + 1]);
				swapped = true;
			}
		}

		if (!swapped)
			break;

		swapped = false;
		--end;

		for (int i = end - 1; i >= start; --i) {
			if (arr[i] > arr[i + 1]) {
				std::swap(arr[i], arr[i + 1]);
				swapped = true;
			}
		}

		++start;
	}
}

inline void Matrices::sortDiagonalsBelowMainDiagonal() {
	for (int i = 1; i < size; ++i) {
		int diagonalSize = size - i;
		int* diagonal = new int[diagonalSize];

		for (int j = 0; j < diagonalSize; ++j) {
			diagonal[j] = squareMatrix[i + j][j];
		}

		cocktailSort(diagonal, diagonalSize);

		for (int j = 0; j < diagonalSize; ++j) {
			squareMatrix[i + j][j] = diagonal[j];
		}
	}
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			cout << squareMatrix[i][j] << "\t";
		}
		cout << endl;
	}

}