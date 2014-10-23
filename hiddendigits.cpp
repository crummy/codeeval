// https://www.codeeval.com/open_challenges/122/

#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    string line;
    while (file >> line) {
        bool foundDigit = false;
        for (int charIndex = 0; charIndex < line.length(); ++charIndex) {
            char ch = line.at(charIndex);
            if (ch >= 'a' && ch <= 'j') {
                foundDigit = true;
                cout << (char)(ch - 'a' + '0');
            } else if (ch >= '0' && ch <= '9') {
                foundDigit = true;
                cout << ch;
            }
        }
        if (!foundDigit) {
            cout << "NONE";
        }
        cout << endl;
    }
}