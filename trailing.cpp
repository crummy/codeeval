// https://www.codeeval.com/open_challenges/32/

#include <fstream>
#include <iostream>

using namespace std;

bool endsOfStringsMatch(string A, string B) {
    if (A.length() < B.length()) {
        return false;
    }
    for (int i = 0; i < B.length() && i < A.length(); ++i) {
        char aChar = A.at(A.length() - 1 - i);
        char bChar = B.at(B.length() - 1 - i);
        if (aChar != bChar) {
            return false;
        }
    }
    return true;
}

int main(int argc, char** argv) {
    
    ifstream file;
    file.open(argv[1]);
    
    string line;
    while (getline(file, line)) {
        if (line.length() == 0) {
            continue;
        }   
        
        string A = line.substr(0, line.find(','));
        string B = line.substr(line.find(',') + 1);
        
        if (endsOfStringsMatch(A, B)) {
            cout << "1" << endl;
        } else {
            cout << "0" << endl;
        }
    }
    return 0;
}