//
//  palprime.cpp
//  codeval1
//
//  Created by Malcolm Crum on 5/9/14.
//
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Determine all primes under 1000
    vector<int> primes;
    for (int potentialPrime = 1; potentialPrime < 1000; potentialPrime++) {
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
    
    // Determine highest palindromes within "primes"
    int highestPrime = primes[0];
    for (int index = 1; index < primes.size(); index++) {
        // Given we know our prime is no longer than 3 characters, we can just compare the first and last character.
        // Also, because our primes are already sorted, we don't have to verify it's the highest - whatever is the
        // latest we are comparing will be higher than the previous.
        string prime = to_string(primes[index]);
        char firstChar = prime.at(0);
        char lastChar = prime.at(prime.size() - 1);
        if (firstChar == lastChar) {
            highestPrime = primes[index];
        }
    }
    
    cout << highestPrime << endl;
    return 0;
}