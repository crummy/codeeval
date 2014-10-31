// https://www.codeeval.com/open_challenges/113/

#include <fstream>
#include <sstream>
#include <iostream>
#include <queue>
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    
    string line;
    while (getline(file, line)) {
        string input;
        queue<int> ints;
        stringstream ss(line);
        while (ss >> input) {
            if (input == "|") {
                break;
            }
            ints.push(atoi(input.c_str()));
        }
        while (ss >> input) {
            int multiplyThis = atoi(input.c_str());
            
            cout << ints.front() * multiplyThis << " ";
            
            ints.pop();
        }
        cout << endl;
    }
    return 0;
}