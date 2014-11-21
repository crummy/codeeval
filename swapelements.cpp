// https://www.codeeval.com/open_challenges/112/

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

vector<int> buildList(string str) {
    vector<int> vec;
    stringstream ss(str);
    int input;
    while (ss >> input) {
        vec.push_back(input);
    }
    return vec;
}

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    
    string line;
    while (getline(file, line)) {
        
        int colonDividerIndex = line.find(':');
        vector<int> elements = buildList(line.substr(0, colonDividerIndex));
        
        stringstream ss(line.substr(colonDividerIndex + 1));
        string swapInstruction;
        while (ss >> swapInstruction) {
            int dashIndex = swapInstruction.find('-');
            int indexA = atoi(swapInstruction.substr(0, dashIndex).c_str());
            int indexB = atoi(swapInstruction.substr(dashIndex + 1).c_str());
            iter_swap(elements.begin() + indexA, elements.begin() + indexB);
        }
        
        for (vector<int>::iterator it = elements.begin(); it != elements.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }
}