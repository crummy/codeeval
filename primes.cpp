//
//  primes.cpp
//  codeval1
//
//  Created by Malcolm Crum on 5/9/14.
//
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

void printPrimes(int primeCount) {
    vector<int> primes;
    for (int potentialPrime = 2; potentialPrime < primeCount; potentialPrime++) {
        bool foundDivisor = false;
        for (int divisor = 2; divisor < potentialPrime; divisor++) {
            if (potentialPrime % divisor == 0) {
                foundDivisor = true;
            }
        }
        if (!foundDivisor) {
            primes.push_back(potentialPrime);
        }
    }
    
    // Putting a second loop over just the primes allows an easier method to prevent a trailing comma
    for (int index = 0; index < primes.size(); index++) {
        cout << primes[index];
        if (index < primes.size() - 1) {
            cout << ",";
        }
    }
    cout << endl;
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
    
    int primeCount;
    while (inputFile >> primeCount) {
        printPrimes(primeCount);
    }
    
    inputFile.close();
    return 0;
}