// https://www.codeeval.com/open_challenges/163/

#include <fstream>
#include <iostream>

using namespace std;

string lines[] = {
    "-**----*--***--***---*---****--**--****--**---**--",
    "*--*--**-----*----*-*--*-*----*-------*-*--*-*--*-",
    "*--*---*---**---**--****-***--***----*---**---***-",
    "*--*---*--*-------*----*----*-*--*--*---*--*----*-",
    "-**---***-****-***-----*-***---**---*----**---**--",
    "--------------------------------------------------"
};

void outputLetterRow(int number, int row) {
    for (int letterIndex = 0; letterIndex < 5; ++letterIndex) {
        cout << lines[row].at(number * 5 + letterIndex);
    }
}

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    
    string line;
    while (getline(file, line)) {
        
        for (int linenr = 0; linenr < 6; ++linenr) {
            for (string::iterator it = line.begin(); it != line.end(); ++it) {
                char ch = *it;
                if (ch >= '0' && ch <= '9') {
                    outputLetterRow(ch - '0', linenr);
                }
                else if (ch == ' ') {
                    cout << "-";
                }
            }
            cout << endl;
        }
        
    }
    return 0;
}