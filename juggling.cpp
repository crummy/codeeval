// https://www.codeeval.com/open_challenges/149/

#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

double binaryToDouble(string str) {
    double total = 0;
    double multiple = 1;
    for (int i = str.length() - 1; i >= 0; --i) {
        if (str.at(i) == '1') {
            total += multiple;
        }
        multiple *= 2;
    }   
    return total;
}

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    
    string line;
    while (getline(file, line)) {
        string flag;
        string sequence;
        stringstream ss(line);
        string binary = "";
        
        while (ss >> flag >> sequence) {
            if (flag == "00") {
                for (string::iterator it = sequence.begin(); it != sequence.end(); ++it) {
                    binary += "1";   
                }
            }
            else if (flag == "0") {
                binary += sequence;
            }
        }
        cout.precision(15);
        cout << binaryToDouble(binary) << endl;
    }
    return 0;
}