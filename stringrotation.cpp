// https://www.codeeval.com/open_challenges/76/

#include <fstream>
#include <iostream>

using namespace std;

bool isRotation(string s1, string s2) {
    s2 = s2 + s2;
    for (int i = 0; i < s1.length(); ++i) {
        bool stringMatchesAtOffset = true;
        for (int j = 0; j < s1.length(); ++j) {
            if (s1.at(j) != s2.at(i + j)) {
                stringMatchesAtOffset = false;
                break;
            }
        }
        if (stringMatchesAtOffset) {
            return true;
        }
    }
    return false;
}


int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    
    string line;
    while (getline(file, line)) {
        
        int commaIndex = line.find(',');
        string left = line.substr(0, commaIndex);
        string right = line.substr(commaIndex + 1);
        
        if (isRotation(left, right)) {
            cout << "True" << endl;
        }
        else {
            cout << "False" << endl;
        }
    }
    
    return 0;
}