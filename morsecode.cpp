// https://www.codeeval.com/open_challenges/116/

#include <sstream>
#include <fstream>
#include <iostream>
#include <map>

using namespace std;

void generateMorseCode(map<string, char> &m) {
    m[".-"] = 'A';
    m["-..."] = 'B';
    m["-.-."] = 'C';
    m["-.."] = 'D';
    m["."] = 'E';
    m["..-."] = 'F';
    m["--."] = 'G';
    m["...."] = 'H';
    m[".."] = 'I';
    m[".---"] = 'J';
    m["-.-"] = 'K';
    m[".-.."] = 'L';
    m["--"] = 'M';
    m["-."] = 'N';
    m["---"] = 'O';
    m[".--."] = 'P';
    m["--.-"] = 'Q';
    m[".-."] = 'R';
    m["..."] = 'S';
    m["-"] = 'T';
    m["..-"] = 'U';
    m["...-"] = 'V';
    m[".--"] = 'W';
    m["-..-"] = 'X';
    m["-.--"] = 'Y';
    m["--.."] = 'Z';
    m[".----"] = '1';
    m["..---"] = '2';
    m["...--"] = '3';
    m["....-"] = '4';
    m["....."] = '5';
    m["-...."] = '6';
    m["--..."] = '7';
    m["---.."] = '8';
    m["----."] = '9';
    m["-----"] = '0';
    
    
}

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    
    map<string, char> morseCode;
    generateMorseCode(morseCode);
    
    string line;
    while (getline(file, line)) {
        string code;
        stringstream ss(line);
        while (ss >> code) {
            if (morseCode.count(code) > 0) {
                cout << morseCode[code];
            } else {
                cout << code;
            }
            // peek two chars ahead to check for space
            if (ss.get()) {
                if (ss.peek() == ' ') {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }
    return 0;
}