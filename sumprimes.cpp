//
//  sumprimes.cpp
//  codeval1
//
//  Created by sonossqa on 5/9/14.
//
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Determine all primes under 1000
    vector<int> primes;
    for (int potentialPrime = 2; primes.size() < 1000; potentialPrime++) {
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
    
    int total = 0;
    for (int index = 0; index < primes.size(); index++) {
        total += primes[index];
    }
    
    cout << total << endl;
    return 0;
}