// https://www.codeeval.com/open_challenges/13/

#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;


int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    while (!file.eof()) 
    {
        string line;
        getline(file, line);
        if (line.length() == 0) {
            break;
        }
        int commaIndex = line.find(',');
        string sentence = line.substr(0, commaIndex);
        string badChars = line.substr(commaIndex + 2);
        for (int charIndex = 0; charIndex < sentence.length(); ++charIndex) {
            char c = sentence.at(charIndex);
            bool isCharAllowed = true;
            for (int badCharIndex = 0; badCharIndex < badChars.length(); ++badCharIndex) {
                if (sentence.at(charIndex) == badChars.at(badCharIndex)) {
                    isCharAllowed = false;
                    break;
                }
            }
            if (isCharAllowed) {
                cout << c;
            }
        }
        cout << endl;
    }
    return 0;
}