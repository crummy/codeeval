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
        int index;
        istringstream indexes(line.substr(line.find('|') + 1));
        while (indexes >> index) {
            cout << line.at(index - 1);
        }
        cout << endl;
    }
    return 0;
}