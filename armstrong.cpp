// https://www.codeeval.com/open_challenges/82/

#include <fstream>
#include <iostream>
#include <math.h>
#include <sstream>

using namespace std;

int sumOfNthPowers(string num) {
    int n = num.length();
    int sum = 0;
    for (string::iterator it = num.begin(); it != num.end(); ++it) {
        int digit = *it - '0';
        sum += pow(digit, n);
    }
    return sum;
}

string intToString(int value) {
    ostringstream ss;
    ss << value;
    return ss.str();
}

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    
    string number;
    while (file >> number) {
        
        int sum = sumOfNthPowers(number);
        string sumString = intToString(sum);
        if (number == sumString) {
            cout << "True" << endl;
        }
        else {
            cout << "False" << endl;
        }
    }
    return 0;
}