// https://www.codeeval.com/open_challenges/147/

#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    string line;
    while (getline(file, line)) {
        int uppercaseCharacters = 0;
        int lowercaseCharacters = 0;
        for (string::iterator it = line.begin(); it != line.end(); it++) {
            char ch = *it;
            if (ch >= 'a' && ch <= 'z') {
                lowercaseCharacters++;   
            }
            else if (ch >= 'A' && ch <= 'Z') {
                uppercaseCharacters++;
            }
        }
        int totalCharacters = lowercaseCharacters + uppercaseCharacters;
        double uppercasePercent = uppercaseCharacters / (double)totalCharacters;
        double lowercasePercent = lowercaseCharacters / (double)totalCharacters;
        cout << setprecision(2) << fixed;
        cout << "lowercase: " << lowercasePercent*100 << " uppercase: " << uppercasePercent*100 << endl;
    }
}