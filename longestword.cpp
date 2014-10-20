//
//  longestword.cpp
//  codeval1
//
//  Created by sonossqa on 7/7/14.
//
//

#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char **argv) {
    ifstream fileInput;
    fileInput.open(argv[1]);
    string line;
    while (getline(fileInput, line, '\n')) {
        string word, longest = "";
        stringstream ss(line);
        while (ss >> word) {
            if (word.length() > longest.length()) {
                longest = word;
            }
        }
        cout << longest << endl;
    }
}