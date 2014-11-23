// https://www.codeeval.com/open_challenges/30/

#include <fstream>
#include <iostream>
#include <sstream>
#include <set>

using namespace std;

set<int> buildSetFrom(stringstream &ss) {
    set<int> s;
    string value;
    while (getline(ss, value, ',')) {
        stringstream valueSS(value);
        int valueInt;
        valueSS >> valueInt;
        s.insert(valueInt);
    }
    return s;
}

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    
    string line;
    while (getline(file, line)) {
        
        stringstream leftStringStream(line.substr(0, line.find(';')));
        set<int> leftSet = buildSetFrom(leftStringStream);
        stringstream rightStringStream(line.substr(line.find(';') + 1));
        set<int> rightSet = buildSetFrom(rightStringStream);
        
        set<int> intersection;
        for (set<int>::iterator it = leftSet.begin(); it != leftSet.end(); ++it) {
            if (rightSet.find(*it) != rightSet.end()) {
                intersection.insert(*it);
            }
        }
        
        for (set<int>::iterator it = intersection.begin(); it != intersection.end(); ++it) {
            cout << *it;
            if (it != --intersection.end()) {
                cout << ",";
            }
        }
        cout << endl;
    }
}