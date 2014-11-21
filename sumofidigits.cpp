//
//  sumofidigits.cpp
//  codeval1
//
//  Created by Malcolm Crum on 5/9/14.
//
//

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void sumOfDigits(string value) {
    int total = 0;
    for (int i = 0; i < value.size(); i++) {
        total += value.at(i) - '0';
    }
    cout << total << endl;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " input.txt" << endl;
        return 1;
    }
    
    ifstream inputFile;
    inputFile.open(argv[1]);
    if (!inputFile.is_open()) {
        cout << "File could not be opened." << endl;
        return 1;
    }
    
    string value;
    while (inputFile >> value) {
        sumOfDigits(value);
    }
    
    inputFile.close();
    return 0;
}