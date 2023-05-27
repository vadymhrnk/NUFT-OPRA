#pragma once
#include <iostream>

using namespace std;

class Arrays
{
public:
	int size;
	Arrays();
	~Arrays();
	void generateArray();
	void sumEven();
	void removeElementDividedBySeven();
	void maxElementAndIndex();
	void firstNegativeThenPositive();
	void shuffleArray();
	bool isSorted();
	void bogoSort();
private:
	int arr[50];
};

Arrays::Arrays()
{
}

Arrays::~Arrays()
{
}

inline void Arrays::generateArray()
{
	srand(time(NULL));
	cout << "Original matrix:";
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100 - 50;
		cout << arr[i] << " ";
	}
}

inline void Arrays::sumEven()
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		if (i % 2 == 0)
		{
			sum = sum + arr[i];
		}
	}

	cout << endl << "sumEven: " << sum << endl;
}

inline void Arrays::removeElementDividedBySeven()
{
	int* newArray = new int[size];
	int count = 0, newSize;
	for (int i = 0; i < size; i++) {
		if (arr[i] % 7 != 0) {
			newArray[count] = arr[i];
			count++;
		}
	}
	newSize = count;
	cout << "removeElementDividedBySeven: ";
	for (int i = 0; i < newSize; i++)
	{
		cout << newArray[i] << " ";
	}
	cout << endl;

	delete[] newArray;
}

inline void Arrays::maxElementAndIndex()
{
	int maxElement = arr[0];
	int maxIndex = 0;

	for (int i = 1; i < size; i++) {
		if (arr[i] > maxElement) {
			maxElement = arr[i];
			maxIndex = i;
		}
	}

	cout << "Maximum element: " << maxElement << endl;
	cout << "Index of maximum element: " << maxIndex << endl;

}

inline void Arrays::firstNegativeThenPositive()
{
	int negIndex = 0;

	for (int i = 0; i < size; i++) {
		if (arr[i] < 0) {
			if (i != negIndex) {
				swap(arr[i], arr[negIndex]);
			}
			negIndex++;
		}
	}
	cout << "firstNegativeThenPositive: ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

inline void Arrays::shuffleArray() {
	for (int i = size - 1; i > 0; i--) {
		int j = rand() % (i + 1);
		swap(arr[i], arr[j]);
	}
}

inline bool Arrays::isSorted() {
	for (int i = 0; i < size - 1; i++) {
		if (arr[i] < arr[i + 1]) {
			return false;
		}
	}
	return true;
}


inline void Arrays::bogoSort() {
	while (!isSorted()) {
		shuffleArray();
	}
	cout << "BogoSort: ";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}