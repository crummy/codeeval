// https://www.codeeval.com/open_challenges/93/

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
    ifstream file;
    if (argc == 1) {
        cout << "No arguments given!" << endl;
        return 1;
    }
    file.open(argv[1]);
    if (!file.is_open()) {
        cout << "Failed to open file!" << endl;
        return 1;
    }
    char ch;
    bool lastCharWasSpace = true;
    while (file >> noskipws >> ch) {
        if (lastCharWasSpace && (ch >= 'a') && (ch <= 'z')) {
            cout << (char)(ch - ('a' - 'A'));
            lastCharWasSpace = false;
        }
        else if (ch < '!') {
            cout << ch;
            lastCharWasSpace = true;
        } else {
            cout << ch;
            lastCharWasSpace = false;
        }
    }
    cout << endl;
    return 0;
}