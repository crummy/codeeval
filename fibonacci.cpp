//
//  fibonacci.cpp
//  codeval1
//
//  Created by sonossqa on 5/13/14.
//
//

#include <iostream>
#include <fstream>
using namespace std;

void printNthFibonacciNumber(int n) {
    int prev = 0;
    int fib = 1;
    if (n == 0) {
        fib = 0; // special case...
    }
    for (int i = 1; i < n; i++) {
        int oldFib = fib;
        fib = prev + fib;
        prev = oldFib;
    }
    cout << fib << endl;
}


int main(int argc, char** argv) {
    ifstream fileInput;
    fileInput.open(argv[1]);
    int value;
    while (fileInput >> value) {
        printNthFibonacciNumber(value);
    }
}