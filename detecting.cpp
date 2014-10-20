// https://www.codeeval.com/open_challenges/5
// not my best work

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
            continue;
        }
        stringstream ss(line);
        int value;
        vector<int> values;
        while (ss >> value) {
            values.push_back(value);
        }
        vector<int> indices(100,-1);
        for (int index = 0; index < values.size(); ++index) {
            value = values[index];
            if (indices[values[index]] > -1) {
                int startIndex = index;
                for (int cycleIndex = indices[value]; values[cycleIndex] == values[index] && cycleIndex < startIndex; ++cycleIndex) {
                    cout << values[cycleIndex] << " ";
                    index++;
                }
                break;
            }
            indices[value] = index;
        }
        cout << endl;
    }
    return 0;
}