// https://www.codeeval.com/open_challenges/104/

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
        string word;
        stringstream ss(line);
        while(getline(ss, word, ';')) {
            if (word.compare("one") == 0) cout << 1;
            if (word.compare("two") == 0) cout << 2;
            if (word.compare("three") == 0) cout << 3;
            if (word.compare("four") == 0) cout << 4;
            if (word.compare("five") == 0) cout << 5;
            if (word.compare("six") == 0) cout << 6;
            if (word.compare("seven") == 0) cout << 7;
            if (word.compare("eight") == 0) cout << 8;
            if (word.compare("nine") == 0) cout << 9;
            if (word.compare("zero") == 0) cout << 0;
        }
        cout << endl;
    }
    return 0;
}