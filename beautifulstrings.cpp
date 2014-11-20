// https://www.codeeval.com/open_challenges/83/

#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    
    string line;
    while (getline(file, line)) {
        vector<int> letters(26, 0);
        
        for (string::iterator it = line.begin(); it != line.end(); ++it) {
            char ch = *it;
            
            if (ch >= 'A' && ch <= 'Z') {
                letters[ch - 'A']++;
            }
            else if (ch >= 'a' && ch <= 'z') {
                letters[ch - ('a' - 'A') - 'A']++;
            }
        }
        
        sort(letters.begin(), letters.end());
        
        int score = 0;
        for (int i = 0; i < letters.size(); ++i) {
            score += letters[i] * (i + 1);
        }
        
        cout << score << endl;
    }
}