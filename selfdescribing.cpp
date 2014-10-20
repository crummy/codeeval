// https://www.codeeval.com/open_challenges/40

#include <fstream>
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

bool isSelfDescribing(string number) {
    vector<int> digitCounts(10);
    for (int digitIndex = 0; digitIndex < number.length(); digitIndex++) {
        char digitChar = number.at(digitIndex);
        int digit = digitChar - '0';
        digitCounts[digit]++;
    }
    for (int digitIndex = 0; digitIndex < number.length(); digitIndex++) {
        char digitChar = number.at(digitIndex);
        int digit = digitChar - '0';
        if (digit != digitCounts[digitIndex]) {
            return false;
        }
    }
    return true;
}

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    while (!file.eof()) 
    {
        string line;
        getline(file, line);
        if (line.length() > 0) {
            cout << (int)isSelfDescribing(line) << endl;
        }
    }
    return 0;
}