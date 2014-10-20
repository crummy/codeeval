// https://www.codeeval.com/open_challenges/52

#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <assert.h>

using namespace std;

string hundreds(string number) {
    int amountLeft = atoi(number.c_str());
    assert(amountLeft < 1000);
    string englishNumber = "";
    string englishNumbers[20] = { "ERROR1", "One", "Two", "Three", "Four", "Five",
                                           "Six", "Seven", "Eight", "Nine", "Ten", "Eleven",
                                           "Twelve", "Thirteen", "Fourteen", "Fifteen",
                                           "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
    string englishTens[10] = { "ERROR2", "ERROR3", "Twenty", "Thirty", "Forty", "Fifty",
                                       "Sixty", "Seventy", "Eighty", "Ninety" };
    if (amountLeft >= 100) {
        int hundredsValue = amountLeft / 100;
        englishNumber = englishNumbers[hundredsValue];
        englishNumber += "Hundred";
        amountLeft -= hundredsValue * 100;
    }
    if (amountLeft > 19) {
        assert(amountLeft < 100);
        int tensValue = amountLeft / 10;
        englishNumber += englishTens[tensValue];
        amountLeft -= tensValue * 10;
    }
    if (amountLeft > 0) {
        assert(amountLeft < 20);
        englishNumber += englishNumbers[amountLeft];
    }
    return englishNumber;
}

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    while (!file.eof()) 
    {
        string line;
        getline(file, line);
        if (line.compare("1") == 0) {
            cout << "OneDollars" << endl;
        }
        else if (line.length() > 6) {
            int millionsDigits = line.length() - 6;
            cout << hundreds(line.substr(0, millionsDigits));
            cout << "Million";
            if (line.substr(millionsDigits, 3).compare("000") != 0) { // An awkward hack to handle numbers like 100000001
                cout << hundreds(line.substr(millionsDigits, 3));
                cout << "Thousand";
            }
            cout << hundreds(line.substr(millionsDigits + 3, 3));
            cout << "Dollars" << endl;
        }
        else if (line.length() > 3) {
            int thousandsDigits = line.length() - 3;
            cout << hundreds(line.substr(0, thousandsDigits));
            cout << "Thousand";
            cout << hundreds(line.substr(thousandsDigits, 3));
            cout << "Dollars" << endl;
        } else if (line.length() > 0) {
            cout << hundreds(line);
            cout << "Dollars" << endl;
        }
    }
    return 0;
}