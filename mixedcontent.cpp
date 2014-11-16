// https://www.codeeval.com/open_challenges/115/

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void splitContent(string line) {
    vector<string> words;
    vector<string> digits;
    
    stringstream ss(line);
    string input;
    while (getline(ss, input, ',')) {
        if (input.at(0) >= 'a' && input.at(0) <= 'z') {
            words.push_back(input);
        }
        else if (input.at(0) >= '0' && input.at(0) <= '9') {
            digits.push_back(input);
        }
        else {
            cout << "UNEXPECTED INPUT: " << input << endl;
        }
    }
    
    for (vector<string>::iterator it = words.begin(); it != words.end(); ++it) {
        cout << *it;
        if (it != --words.end()) {
            cout << ",";
        }
        else if (digits.size() > 0) {
            cout << "|";
        }
    }
    
    for (vector<string>::iterator it = digits.begin(); it != digits.end(); ++it) {
       cout << *it;
        if (it != --digits.end()) {
            cout << ",";
        }
    }
    
    cout << endl;
}

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    
    string line;
    while (getline(file, line)) {
        splitContent(line);
    }
    return 0;
}