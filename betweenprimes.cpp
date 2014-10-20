//
//  betweenprimes.cpp
//  codeval1
//
//  Created by sonossqa on 5/9/14.
//
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

void countPrimesBetween(int from, int to) {
    int totalPrimesFound = 0;
    for (int potentialPrime = from; potentialPrime <= to; potentialPrime++) {
        bool foundDivisor = false;
        for (int divisor = 2; divisor < potentialPrime; divisor++) {
            if (potentialPrime % divisor == 0) {
                foundDivisor = true;
            }
        }
        if (!foundDivisor && potentialPrime > 1) {
            totalPrimesFound++;
        }
    }
    cout << totalPrimesFound << endl;
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
    
    int from, to;
    char delim;
    while (inputFile >> from >> delim >> to) {
        countPrimesBetween(from, to);
    }
    
    inputFile.close();
    return 0;
}