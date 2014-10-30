// https://www.codeeval.com/open_challenges/81/

#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <stdlib.h>

using namespace std;

int totalTimesIntsAddToZero(vector<int> &values) {
    int combinations = 0;
    for (int i = 0; i < values.size(); ++i) {
        for (int j = i + 1; j < values.size(); ++j) {
            for (int k = j + 1; k < values.size(); ++k) {
                for (int l = k + 1; l < values.size(); ++l) {
                    if (values[i] + values[j] + values[k] + values[l] == 0) {
                        combinations++;
                    }
                }
            }
        }
    }
    return combinations;
}

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    
    string line;
    while (getline(file, line)) {
        
        vector<int> ints;
        stringstream ss(line);
        string valueStr;
        while (getline(ss, valueStr, ',')) {
            ints.push_back(atoi(valueStr.c_str()));
        }
        
        cout << totalTimesIntsAddToZero(ints) << endl;
    }
}