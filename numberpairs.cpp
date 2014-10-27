// https://www.codeeval.com/open_challenges/34/

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <stdlib.h>

using namespace std;

vector<int> split(const char* str, char delim = ' ') {
    vector<int> result;
    do {
        const char *begin = str;
        while (*str != delim && *str) {
            str++;
        }
        result.push_back(atoi(string(begin, str).c_str()));
    } while (0 != *str++);
    return result;
}

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    
    string line;
    while (getline(file, line)) {
        int endOfNumberString = line.find(';');
        string numberString = line.substr(0, endOfNumberString);
        string sumString = line.substr(endOfNumberString + 1);
        int sum = atoi(sumString.c_str());
        vector<int> numbers = split(numberString.c_str(), ',');
        bool foundPair = false;
        
        for (int i = 0; i < numbers.size(); ++i) {
            for (int j = i + 1; j < numbers.size(); ++j) {
                if (numbers[i] + numbers[j] == sum) {
                    if (foundPair) {
                        cout << ";";
                    }
                    cout << numbers[i] << "," << numbers[j];
                    foundPair = true;
                }
            }
        }
        if (!foundPair) {
            cout << "NULL";
        }
        cout << endl;
    }
}