// https://www.codeeval.com/open_challenges/16/

#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    int number;
    while (file >> number) {
        
        // special case.
        if (number == 0) {
            cout << "0" << endl;
            continue;
        }
        
        int binaryIndex = 1;
        while (binaryIndex < number) {
            binaryIndex *= 2;
        }
        if (binaryIndex != number) {
            binaryIndex /= 2;
        }
        
        int numberOfOnes = 0;
        while (binaryIndex > 0) {
            if (number >= binaryIndex) {
                numberOfOnes++;
                number -= binaryIndex;
                binaryIndex /= 2;
            } else {
                binaryIndex /= 2;
            }
        }
        cout << numberOfOnes << endl;
    }
}