//
//  oddnumbers.cpp
//  codeval1
//
//  Created by sonossqa on 5/13/14.
//
//

#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    ifstream fileInput;
    fileInput.open(argv[1]);
    int value;
    while (fileInput >> value) {
        printNthFibonacciNumber(value);
    }
}