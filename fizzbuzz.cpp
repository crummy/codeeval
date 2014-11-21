//
//  fizzbuzz.cpp
//  codeval1
//
//  Created by Malcolm Crum on 5/8/14.
//
//

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void fizzbuzz(int fizz, int buzz, int until) {
    stringstream ss;
    for (int i = 1; i <= until; i++) {
        if (i % fizz == 0 && i % buzz == 0) {
            ss << "FB ";
        } else if (i % fizz == 0) {
            ss << "F ";
        } else if (i % buzz == 0) {
            ss << "B ";
        } else {
            ss << to_string(i) << " ";
        }
    }
    cout << ss.str() << endl;
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
    
    int fizz, buzz, until;
    while (inputFile >> fizz >> buzz >> until) {
        fizzbuzz(fizz, buzz, until);
    }
    
    inputFile.close();
    return 0;
}