#include <iostream>
#include<Windows.h>

using namespace std;

int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);

	cout << "           ____" << endl;
	cout << "         / |   |\\" << endl;
	cout << "  _____/ \033[1;34m@\033[93m |   | \\" << endl;
	cout << " |\033[1;95m>\033[93m  . .   |   |  \\" << endl;
	cout << "  \\   .    \033[1;90m|||||\033[93m   \\__________________________" << endl;
	cout << "   \033[1;90m|||||||\033[93m\\     \033[1;37m__\033[93m      \033[1;37m_____\033[93m       \033[1;37m/   \\\033[93m     |\\" << endl;
	cout << "            \\  \033[1;37m|  |\033[93m    \033[1;37m/     | \033[93m     \033[1;37m|   |\033[93m     | \\" << endl;
	cout << "             \\  \033[1;37m\\/\033[93m    \033[1;37m|__    |\033[93m      \033[1;37m|__/\033[93m      |  \\" << endl;
	cout << "               \\         \033[1;37m\\__/\033[93m                /    \\" << endl;
	cout << "                |   ____________------\\     |      \\" << endl;
	cout << "                |  | |                ||    /       \\ " << endl;
	cout << "                |  | |                ||  |          \\" << endl;
	cout << "                |  | |                ||  |           \\" << endl;
	cout << "                |  | |                ||  |" << endl;
	cout << "               (__/_/                ((__/" << endl;
	return 0;
}