// https://www.codeeval.com/open_challenges/70/

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
        
        // find how many digits we need.
        int binaryIndex = 1;
        while (binaryIndex < number) {
            binaryIndex *= 2;
        }
        if (binaryIndex != number) {
            binaryIndex /= 2;
        }
        // at this point, binaryIndex is the greatest power of two less than or equal to our number.
        
        while (binaryIndex > 0) {
            if (number >= binaryIndex) {
                cout << '1';
                number -= binaryIndex;
                binaryIndex /= 2;
            } else {
                cout << '0';
                binaryIndex /= 2;
            }
        }
        cout << endl;
    }
}