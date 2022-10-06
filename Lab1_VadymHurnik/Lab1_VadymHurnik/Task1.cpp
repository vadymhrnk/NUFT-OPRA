/*file name: Lab1_VadymHurnik.sln
*студент: Гурнік Вадим Миколайович
*група: КН – 1 - 4
*дата створення: 04/10/2022
*дата останньої зміни: 05/10/2022
*лабораторна робота №1
*тема: Алгоритмізація та програмування задач лінійної структури
*/
#include <iostream>
#include<math.h>

using namespace std;

int main()
{
	float alpha = 0;
	float Z1 = 0, Z2 = 0, Z3 = 0;

	cout << "Enter value of alpha: ";
	cin >> alpha;

	Z1 = 1 - 1 / 4 - pow(sin(2 * alpha), 2) + cos(2 * alpha);
	Z2 = pow(cos(alpha), 2) + pow(cos(alpha), 4);
	Z3 = 2 * Z1 + 1 / Z2;

	cout << "Values:\nZ1: " << Z1 << endl << "Z2: " << Z2 << endl << "Z3: " << Z3;
	return 0;
}
