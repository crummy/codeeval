// https://www.codeeval.com/open_challenges/84/

#include <iostream>
#include <fstream>

using namespace std;

bool isBalanced(string str);

// - An empty string "" 
bool isEmpty(string str) {
    return str.length() == 0;
}

// - One or more of the following characters: 'a' to 'z', ' ' (a space) or ':' (a colon) 
bool isLegalChars(string str) {
    for(string::iterator it = str.begin(); it != str.end(); ++it) {
        char ch = *it;
        if ((ch < 'a' || ch > 'z') && ch != ':' && ch != ' ') {
            return false;
        }
    }
    return true;
}

// - An open parenthesis '(', followed by a message with balanced parentheses, followed by a close parenthesis ')'.
bool isContainingBalanced(string str) {
    char firstChar = str.at(0);
    char lastChar = str.at(str.length() - 1);
    if (firstChar == '(' && lastChar == ')') {
        string innerStr = str.substr(1, str.length() - 2);
        return isBalanced(innerStr);
    }
    else {
        return false;
    }
}

// - A message with balanced parentheses followed by another message with balanced parentheses. 
bool isDoubleBalanced(string str) {
    if ((str.find(')') == -1) && (str.find('(') == -1)) { // A "double" message will always have at least one paren.
        return false;
    }
    for (int separator = 1; separator < str.length(); ++separator) {
        string leftStr = str.substr(0, separator);
        string rightStr = str.substr(separator);
        if (isBalanced(leftStr) && isBalanced(rightStr)) {
            return true;
        }
    }
    return false;
}

// - A smiley face ":)" or a frowny face ":(" 
bool isEmoticon(string str) {
    if ((str.compare(":)") == 0) || (str.compare(":(") == 0)) {
        return true;
    }
    return false;
}

bool isBalanced(string str) {
    if (isEmpty(str)) {
        return true;
    }
    else if (isLegalChars(str)) {
        return true;
    }
    else if (isContainingBalanced(str)) {
        return true;
    }
    else if (isDoubleBalanced(str)) {
        return true;
    }
    else if (isEmoticon(str)) {
        return true;
    }
    return false;
}

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    
    string line;
    while (getline(file, line)) {
        if (isBalanced(line)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}