/*file name: Task2.cpp
*студент: Гурнік Вадим Миколайович
*група: КН – 1 - 4
*дата створення: 04/10/2022
*дата останньої зміни: 05/10/2022
*лабораторна робота №1
*тема: Алгоритмізація та програмування задач лінійної структури
*завдання: Розробити блок-схему алгоритму для розв‘язку задачі та
реалізувати його мовою С\С++ відповідно варіанту індивідуального завдання, що
наведено у таблиці Г.2 з додатку Г.
*/
#include <iostream>

using namespace std;

int main()
{
	float A = 0, B = 0, C = 0;
	float sizeProduct = 0;

	cout << "Enter point A: ";
	cin >> A;

	cout << "Enter point B: ";
	cin >> B;

	cout << "Enter point C (between A and B): ";
	cin >> C;

	if (B > C && C > A)
	{
		sizeProduct = (B - C) * (C - A);
	}
	else if (A > C && C > B)
	{
		sizeProduct = (A - C) * (C - B);
	}
	cout << "Product: " << sizeProduct;

	return 0;
}
