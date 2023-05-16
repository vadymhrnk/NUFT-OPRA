#include <iostream>
#include "StaticLib.h"
#include "DynamicLib.h"

using namespace StaticLibrary;

int main()
{
	StaticLib lib;
	int n = 3;
	int arr[] = { 1,2,2 };
	if (lib.isPalindrome(arr, n))
	{
		cout << "Is";
	}
	else
	{
		cout << "No";
	}
	cout << endl;

	int arr2[] = { 1,2,3,55,8,0,-3 };
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	int max = findMax(arr2, n2);
	cout << "Max: " << max;

}