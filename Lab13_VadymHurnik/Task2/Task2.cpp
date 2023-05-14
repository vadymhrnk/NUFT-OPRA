#include <iostream>
#include <string>

using namespace std;

void replaceBrackets(string& str) {
    for (char& c : str) {
        if (c == '(') {
            c = '[';
        }
        else if (c == ')') {
            c = ']';
        }
    }
}

int main() {
    string str1 = "";
    cout << "Enter text: ";
    cin >> str1;
    replaceBrackets(str1);
    cout << str1 << "\n";

    return 0;
}
