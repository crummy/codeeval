// https://www.codeeval.com/open_challenges/107/

#include <fstream>
#include <iostream>

using namespace std;

bool isRepetition(string rep, string line) {
    //cout << "testing " << rep << " in " << line << endl;
    if (line.length() == 0) {
        return true;
    }
    else if (rep.length() > line.length()) {
        return false;
    }
    else if (line.substr(0, rep.length()) == rep) {
        return isRepetition(rep, line.substr(rep.length()));
    }
    else {
        return false;
    }
}

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    
    string line;
    while (getline(file, line)) {
        
        int minPeriod = line.length();
        for (int i = line.length() / 2; i > 0; --i) {
            string repetition = line.substr(0, i);
            if (isRepetition(repetition, line)) {
                minPeriod = i;
            }
        }
        
        cout << minPeriod << endl;
    }
}