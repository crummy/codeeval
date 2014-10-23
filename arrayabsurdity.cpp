// https://www.codeeval.com/open_challenges/41/

#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    string line;
    while (file >> line) {
        
        string arraySize;
        arraySize = line.substr(0, line.find(';'));
        int size = atoi(arraySize.c_str());
        int values[size*2];
        for (int i = 0; i < size; ++i) {
            values[i] = -1;
        }
        stringstream numbers(line.substr(line.find(';') + 1));
        string stringValue;
        while (getline(numbers, stringValue, ',')) {
            int value = atoi(stringValue.c_str());
            if (values[value] > -1) {
                cout << value << endl;
                break;
            } else {
                values[value] = 1;
            }
        }
    }
}