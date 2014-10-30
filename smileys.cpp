// https://www.codeeval.com/open_challenges/84/

#include <iostream>
#include <fstream>

using namespace std;

bool isBalanced(string str, int parenDepth);

bool isBalanced(string str, int parenDepth) {
    for (int chIndex = 0; chIndex < str.length(); ++chIndex) {
        char ch = str.at(chIndex);
        //cout << parenDepth << " " << ch << endl;
        if (ch == '(') {
            parenDepth++;
        }
        else if (ch == ')') {
            parenDepth--;
        }
        else if (ch == '[') {
            if (isBalanced(str.substr(chIndex + 1), parenDepth)) {
                // must be a smiley
            }
            else if (isBalanced(str.substr(chIndex + 1), parenDepth + 1)) {
                parenDepth++;
            }
        }
        else if (ch == ']') {
            if (isBalanced(str.substr(chIndex + 1), parenDepth)) {
                // must be a smiley
            }
            else if (isBalanced(str.substr(chIndex + 1), parenDepth - 1)) {
                parenDepth--;
            }
        }
        if (parenDepth == -1) {
            return false;
        }
    }
    return (parenDepth == 0);
}

// thanks http://stackoverflow.com/questions/5878775/how-to-find-and-replace-string
string replaceAll(string subject, string search, string replace) {
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != string::npos) {
        subject.replace(pos, search.length(), replace);
        pos += replace.length();
    }
    return subject; 
}

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    
    string line;
    while (getline(file, line)) {
        line = replaceAll(line, ":(", "[");
        line = replaceAll(line, ":)", "]");
        if (isBalanced(line, 0)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}