// https://www.codeeval.com/open_challenges/39/

#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <map>

using namespace std;

bool isHappyNumber(int number, map<int, bool> &previousNumbers) {
    if (number == 1) {
        return true;
    }
    if (previousNumbers.count(number) > 0) {
        return false;
    }
    previousNumbers[number] = true;
    int newNumber = 0;
    while (number > 0) {
        newNumber += (number % 10)*(number % 10);
        number = number / 10;
    }
    return isHappyNumber(newNumber, previousNumbers);
}

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    while (!file.eof()) 
    {
        string line;
        getline(file, line);
        if (line.length() == 0) {
            break;
        }
        int number = atoi(line.c_str());
        map<int, bool> previousNumbers;
        cout << (int)isHappyNumber(number, previousNumbers) << endl;
    }
    return 0;
}