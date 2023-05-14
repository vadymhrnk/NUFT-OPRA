#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int ROWS = 3;
const int COLS = 3;

void fillMatrix(int arr[ROWS][COLS])
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

void printMatrix(int arr[ROWS][COLS])
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

void sumAndCountNegatives(int arr[ROWS][COLS], int& sum, int& count)
{
    sum = 0;
    count = 0;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (arr[i][j] < 0)
            {
                sum += arr[i][j];
                count++;
            }
        }
    }
}

int main()
{
    int arr[ROWS][COLS];
    fillMatrix(arr);
    printMatrix(arr);
    int sum, count;
    sumAndCountNegatives(arr, sum, count);
    cout << "Sum of negative elements: " << sum << endl;
    cout << "Number of negative elements: " << count << endl;
    return 0;
}
