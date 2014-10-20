// https://www.codeeval.com/open_challenges/97/

#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <vector>

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
        int total = 0;
        int columnMultiplier = 1;
        for (int charIndex = line.length() - 1; charIndex >= 0; --charIndex) {
            char hexDigit = line.at(charIndex);
            if (hexDigit <= '9') {
                total += (hexDigit - '0') * columnMultiplier;
            } else {
                total += (hexDigit - 'a' + 10) * columnMultiplier;
            }
            columnMultiplier *= 16;
        }
        cout << total << endl;
    }
    return 0;
}