// https://www.codeeval.com/open_challenges/96/

#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;


int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    while (!file.eof()) 
    {
        string line;
        getline(file, line);
        if (line.length() == 0) {
            break;
        }
        for (int charIndex = 0; charIndex < line.length(); ++charIndex) {
            char c = line.at(charIndex);
            if (c >= 'a' && c <= 'z') {
                cout << (char)(c - ('a' - 'A'));
            }
            else if (c >= 'A' && c <= 'Z') {
                cout << (char)(c + ('a' - 'A'));
            }
            else {
                cout << c;    
            }
        }
        cout << endl;
    }
    return 0;
}