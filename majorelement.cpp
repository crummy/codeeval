// https://www.codeeval.com/open_challenges/132/

#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    
    string line;
    while (getline(file, line)) {
        vector<int> numbers(100, 0);
        string value;
        stringstream ss(line);
        int totalNumbersRead = 0;
        
        while (getline(ss, value, ',')) {
            int number = atoi(value.c_str());
            numbers[number]++;
            totalNumbersRead++;
        }
        
        int biggestNumber = -1;
        int biggestIndex = -1;
        for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
            if (*it > biggestNumber) {
                biggestNumber = *it;
                biggestIndex = it - numbers.begin();
            }
        }
        
        if (biggestNumber * 2 > totalNumbersRead) {
            cout << biggestIndex << endl;
        }
        else {
            cout << "None" << endl;
        }
    }
}