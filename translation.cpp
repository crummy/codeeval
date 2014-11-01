// https://www.codeeval.com/open_challenges/121/

#include <fstream>
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char** argv) {
    
    // couldn't figure out the algorithm, so just hardcode it and guess the two missing chars
    map<char, char> translation;
    translation['y'] = 'a';
    translation['n'] = 'b';
    translation['f'] = 'c';
    translation['i'] = 'd';
    translation['c'] = 'e';
    translation['w'] = 'f';
    translation['l'] = 'g';
    translation['b'] = 'h';
    translation['k'] = 'i';
    translation['u'] = 'j';
    translation['o'] = 'k';
    translation['m'] = 'l';
    translation['x'] = 'm';
    translation['s'] = 'n';
    translation['e'] = 'o';
    translation['v'] = 'p';
    translation['z'] = 'q';
    translation['p'] = 'r';
    translation['d'] = 's';
    translation['r'] = 't';
    translation['j'] = 'u';
    translation['g'] = 'v'; // ?
    translation['t'] = 'w';
    translation['h'] = 'x'; // ?
    translation['a'] = 'y';
    translation['q'] = 'z';
    
    ifstream file;
    file.open(argv[1]);
    
    while (!file.eof()) {
        char ch = file.get();
        if (ch >= 'a' && ch <= 'z') {
            cout << translation[ch];
        } else {
            cout << ch;
        }
    }
    cout << endl;
}