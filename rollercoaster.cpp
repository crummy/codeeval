// https://www.codeeval.com/open_challenges/156/

#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    
    string line;
    while(getline(file, line)) {
        
        bool lastWasUpper = false;
        for (string::iterator it = line.begin(); it != line.end(); ++it) {
            char ch = *it;
            if (ch >= 'A' && ch <= 'Z') {
                if (lastWasUpper) {
                    cout << (char)(ch + ('a' - 'A'));
                    lastWasUpper = false;
                }
                else {
                    cout << ch;
                    lastWasUpper = true;
                }
            }
            else if (ch >= 'a' && ch <= 'z') {
                if (lastWasUpper) {
                    cout << ch;
                    lastWasUpper = false;
                }
                else {
                    cout << (char)(ch - ('a' - 'A'));
                    lastWasUpper = true;
                }
            }
            else {
                cout << ch;
            }
        }
        
        cout << endl;
    }
    return 0;
}