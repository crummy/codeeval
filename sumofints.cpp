//
//  sumofints.cpp
//  codeval1
//
//  Created by Malcolm Crum on 5/13/14.
//
//

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv) {
    ifstream fileInput;
    fileInput.open(argv[1]);
    int value;
    int total = 0;
    while (fileInput >> value) {
        total += value;
    }
    cout << total << endl;
}