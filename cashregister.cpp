// https://www.codeeval.com/open_challenges/54/

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <assert.h>
#include <stdlib.h>

using namespace std;

// Necessary to convert cents here to avoid rounding issues.
string cashStringFor(int cents) {
    string str = "";
    while (cents >= 10000) {
        str += "ONE HUNDRED,";
        cents -= 10000;
    }
    while (cents >= 5000) {
        str += "FIFTY,";
        cents -= 5000;
    }
    while (cents >= 2000) {
        str += "TWENTY,";
        cents -= 2000;
    }
    while (cents >= 1000) {
        str += "TEN,";
        cents -= 1000;
    }
    while (cents >= 500) {
        str += "FIVE,";
        cents -= 500;
    }
    while (cents >= 200) {
        str += "TWO,";
        cents -= 200;
    }
    while (cents >= 100) {
        str += "ONE,";
        cents -= 100;
    }
    while (cents >= 50) {
        str += "HALF DOLLAR,";
        cents -= 50;
    }
    while (cents >= 25) {
        str += "QUARTER,";
        cents -= 25;
    }
    while (cents >= 10) {
        str += "DIME,";
        cents -= 10;
    }
    while (cents >= 5) {
        str += "NICKEL,";
        cents -= 5;
    }
    while (cents > 0) {
        str += "PENNY,";
        cents -= 1;
    }
    assert(cents == 0);
    return str.substr(0, str.length() - 1); // trim the trailing comma
}

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    
    string line;
    while (file >> line) {
        
        stringstream ss(line);
        string priceStr, cashStr;
        getline(ss, priceStr, ';');
        getline(ss, cashStr);
        double price = strtod(priceStr.c_str(), NULL);
        double cash = strtod(cashStr.c_str(), NULL);
        
        if (cash < price) {
            cout << "ERROR" << endl;
        }
        else if (cash == price) {
            cout << "ZERO" << endl;
        }
        else {
            cout << cashStringFor(cash*100 - price*100) << endl;
        }
    }
}