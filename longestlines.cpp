// https://www.codeeval.com/open_challenges/2

#include <fstream>
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    string numberOfLinesToOutputString;
    getline(file, numberOfLinesToOutputString);
    int numberOfLinesToOutput = atoi(numberOfLinesToOutputString.c_str());
    vector<string> lines;
    while (!file.eof()) 
    {
        string line;
        getline(file, line);
        lines.push_back(line);
    }
    for (int lineCount = 0; lineCount < numberOfLinesToOutput; lineCount++) {
        vector<string>::iterator longestLine = lines.begin();
        for (vector<string>::iterator iter = lines.begin(); iter != lines.end(); ++iter) {
            if ((*iter).length() > (*longestLine).length()) {
                longestLine = iter;
            }
        }
        cout << *longestLine << endl;
        lines.erase(longestLine);
    }
    return 0;
}