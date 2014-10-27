// https://www.codeeval.com/open_challenges/12/

#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    string word;
    while (getline(file, word)) {
        vector<int> charCount(26, 0);
        for (int i = 0; i < word.length(); ++i) {
            char ch = word.at(i);
            charCount[ch - 'a']++;
        }
        for (int i = 0; i < word.length(); ++i) {
            char ch = word.at(i);
            if (charCount[ch - 'a'] == 1) {
                cout << ch << endl;
                break;
            }
        }
    }
}