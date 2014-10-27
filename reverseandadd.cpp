// https://www.codeeval.com/open_challenges/45/

#include <fstream>
#include <iostream>
#include <sstream>
#include <assert.h>

using namespace std;

bool isPalindrome(int number) {
    stringstream ss;
    ss << number;
    string num = ss.str();
    int leftIndex = 0;
    int rightIndex = num.length() - 1;
    while (leftIndex <= rightIndex) {
        if (num.at(leftIndex) != num.at(rightIndex)) {
            return false;
        }
        leftIndex++;
        rightIndex--;
    }
    return true;
}

int reverseInt(int number) {
    stringstream ss;
    ss << number;
    string num = ss.str();
    stringstream rss;
    for (string::reverse_iterator rit = num.rbegin(); rit != num.rend(); ++rit) {
        rss << *rit;
    }
    int rnum;
    rss >> rnum;
    return rnum;
}

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    int number;
    while (file >> number) {
        int iterations = 0;
        while (!isPalindrome(number)) {
            iterations++;
            assert(iterations < 100);
            number += reverseInt(number);
        }
        cout << iterations << " " << number << endl;
    }
}