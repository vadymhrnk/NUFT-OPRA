#include <iostream>
#include <string>
using namespace std;

void addComma(string& str) {
    for (int i = 0; i < str.length(); i++) {
        if (isdigit(str[i]) && i + 1 < str.length() && str[i + 1] == '+') {
            str.insert(i + 1, ",");
            i += 1;
        }
    }
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    addComma(str);
    cout << "Modified string: " << str << endl;
    return 0;
}
