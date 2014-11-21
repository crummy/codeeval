//
//  lowercase.cpp
//  codeval1
//
//  Created by Malcolm Crum on 5/9/14.
//
//

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv) {
    ifstream fileInput;
    fileInput.open(argv[1]);
    char letter;
    while (fileInput.get(letter)) {
        if (letter >= 'A' && letter <= 'Z') {
            printf("%c", letter - ('A' - 'a'));
        } else {
            printf("%c", letter);
        }
    }
}