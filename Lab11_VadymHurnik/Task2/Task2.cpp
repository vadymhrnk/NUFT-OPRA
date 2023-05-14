#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void shellSort(int arr[], int n) {
	for (int gap = n / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < n; i++) {
			int temp = arr[i];
			int j;
			for (j = i; j >= gap && arr[j - gap] < temp; j -= gap) {
				arr[j] = arr[j - gap];
			}
			arr[j] = temp;
		}
	}
}

int main() {

	srand(time(0));
	const int n = 5;
	int matrix[n][n];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = rand() % 50;
		}
	}

	int counter = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++)
		{

		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}

	return 0;
}
