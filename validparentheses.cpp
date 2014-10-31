// https://www.codeeval.com/open_challenges/68/

#include <fstream>
#include <iostream>
#include <stack>

using namespace std;

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    
    string line;
    while (getline(file, line)) {
        stack<char> brackets;
        bool valid = true;
        for (string::iterator it = line.begin(); it != line.end(); ++it) {
            char ch = *it;
            if (ch == '(' || ch == '[' || ch == '{') {
                brackets.push(*it);
            }
            else if (brackets.empty()) {
                valid = false;
                break;
            }
            else if (ch != brackets.top() + 1 && ch != brackets.top() + 2) { // haha
                valid = false;
                break;
            } else {
                brackets.pop();
            }
        }
        
        if (valid && brackets.empty()) {
            cout << "True" << endl;
        }
        else {
            cout << "False" << endl;
        }
    }
    return 0;
}