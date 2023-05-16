#include <iostream>
#include "DynamicLib.h"
#include "StaticLib.h"

using namespace std;
using namespace StaticLibrary;

int main()
{
	StaticLib lib;
	int n1 = 3;
	int arr1[] = { 1,2,2 };
	if (lib.isPalindrome(arr1, n1))
	{
		cout << "Is";
	}

    int arr2[] = { 1,2,3,55,8,0,-3 };
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int max = findMax(arr2,n2);
    cout << "Max: " << max;
}