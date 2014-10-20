// https://www.codeeval.com/open_challenges/158/

#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <vector>

using namespace std;

void partialBubbleSort(vector<int> &values, int iterations) {
    for (int iteration = 0; iteration < iterations; ++iteration) {
        for (int index = 0; index < values.size() - 1; ++index) {
            if (values[index] > values[index + 1]) {
                int temp = values[index + 1];
                values[index + 1] = values[index];
                values[index] = temp;
            }
        }
    }
}

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
        stringstream ss(line);
        vector<int> values;
        string value;
        while (ss >> value) {
            values.push_back(atoi(value.c_str()));
        }
        int iterations = values.back();
        values.pop_back();
        values.pop_back();
        partialBubbleSort(values, iterations);
        for (int number : values) {
            cout << number << " ";
        }
        cout << endl;
    }
    return 0;
}