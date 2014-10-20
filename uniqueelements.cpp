// https://www.codeeval.com/open_challenges/29

#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    while (!file.eof()) 
    {
        string line;
        getline(file, line);
        if (line.length() == 0)
           continue; //ignore all empty lines
        else 
        {
            map<int, bool> values;
            string value;
            stringstream ss(line);
            while (getline(ss, value, ',')) {
                values.insert(pair<int, bool>(atoi(value.c_str()), true));
            }
            for (map<int, bool>::iterator it = values.begin(); it != values.end();) {
                cout << it->first;
                if (++it != values.end()) {
                    cout << ",";
                }
            }
            cout << endl;
        }
    }
}