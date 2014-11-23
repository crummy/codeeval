// https://www.codeeval.com/open_challenges/131/

#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    
    string line;
    while (getline(file, line)) {
        
        stringstream ss(line);
        string bothNumbers;
        ss >> bothNumbers;
        string pattern;
        ss >> pattern;
        
        int dividerIndex = pattern.find('-');
        if (dividerIndex == -1) {
            dividerIndex = pattern.find('+');
        }
        
        int firstNumber;
        stringstream firstNumberSS(bothNumbers.substr(0, dividerIndex));
        firstNumberSS >> firstNumber;
        int secondNumber;
        stringstream secondNumberSS(bothNumbers.substr(dividerIndex));
        secondNumberSS >> secondNumber;
        
        if (pattern.find('-') != -1) {
            cout << firstNumber - secondNumber << endl;
        }
        else {
            cout << firstNumber + secondNumber << endl;
        }
    }
}