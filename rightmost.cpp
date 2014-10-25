// https://www.codeeval.com/open_challenges/91/

#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    string line;
    while(getline(file, line)) {
        char charToFind = line.at(line.length() - 1);
        int index = line.substr(0, line.length() - 2).find_last_of(charToFind);
        cout << index << endl;
    }
}