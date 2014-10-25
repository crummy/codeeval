// https://www.codeeval.com/open_challenges/167/

#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    string line;
    while (getline(file, line)) {
        if (line.length() <= 55) {              // short sentence: print it all
            cout << line << endl;
            continue;
        }
        else if (line.find(' ') == -1) {        // no spaces: print first 40 chars
            line = line.substr(0, 40);
        }
        else if (line.find(' ') > 40) {         // no spaces in first 40 chars: print first 40 chars
            line = line.substr(0, 40);
        }
        else if (line.at(40) == ' ') {        // last char is a space
            line = line.substr(0, 40);
        }
        else {                                  // last chars are letters
            line = line.substr(0, 40);
            while (line.at(line.length() -1) != ' ') {
                line = line.substr(0, line.length() - 1);
            }
            line = line.substr(0, line.length() - 1);
        }
        cout << line << "... <Read More>" << endl;
    }
}