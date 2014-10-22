// https://www.codeeval.com/open_challenges/10/

#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        char ch;
        vector<char> chars;
        while (ss >> ch) {
            chars.push_back(ch);
        }
        int m = chars.back() - '0';
        chars.pop_back();
        if (chars.back() < 'A') { // must be a number
            int m2 = chars.back() - '0';
            chars.pop_back();
            m = m + (10*m2);
        }
        int index = chars.size() - m;
        if (index >= 0) {
            cout << chars[index] << endl;
        }
    }
    return 0;
}