//
//  penultimate.cpp
//  codeval1
//
//  Created by Malcolm Crum on 7/7/14.
//
//

#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char **argv) {
    ifstream fileInput;
    fileInput.open(argv[1]);
    vector<string> words;
    string line, word;
    while (getline(fileInput, line, '\n')) {
        stringstream ss(line);
        while (ss >> word) {
            words.push_back(word);
        }
        words.pop_back();
        cout << words.back() << endl;
    }
}