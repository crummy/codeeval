// https://www.codeeval.com/open_challenges/119/

#include <map>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

string goodChain(string line) {
    if (line.find("BEGIN") == string::npos || line.find("END") == string::npos) {
        return "BAD";
    }
    map<string, string> transitions;
    stringstream ss(line);
    string pair;
    while (getline(ss, pair, ';')) {
        string key = pair.substr(0, pair.find('-'));
        string value = pair.substr(pair.find('-') + 1);
        if (transitions.find(value) == transitions.end()) {
            transitions[value] = key;
        } else {
            return "BAD";
        }
    }
    
    string address = "END";
    int transitionCount = 0;
    while (address != "BEGIN") {
        address = transitions[address];
        transitionCount++;
    }
    if (transitionCount != transitions.size()) {
        return "BAD";
    }
    else {
        return "GOOD";
    }
}

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    
    string line;
    while (getline(file, line)) {
        
        cout << goodChain(line) << endl;
        
    }
}