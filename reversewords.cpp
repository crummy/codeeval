//
//  reversewords.cpp
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

void reverseWords(string line) {
    stringstream ss(line);
    vector<string> words;
    string word;
    
    while (ss >> word) {
        words.push_back(word);
    }
    
    for (int i = words.size() - 1; i >= 0; i--) {
        cout << words[i] << " ";
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
    
    int fizz, buzz, until;
    while (inputFile) {
        string line;
        getline(inputFile, line);
        reverseWords(line);
    }
    
    inputFile.close();
    return 0;
}