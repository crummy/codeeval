// https://www.codeeval.com/open_challenges/106/

#include <fstream>
#include <iostream>

using namespace std;

string toRoman(int num) {
    if (num - 1000 >= 0) {
        return "M" + toRoman(num - 1000);
    }
    else if (num - 900 >= 0) {
        return "CM" + toRoman(num - 900);
    }
    else if (num - 500 >= 0) {
        return "D" + toRoman(num - 500);
    }
    else if (num - 400 >= 0) {
        return "CD" + toRoman(num - 400);
    }
    else if (num - 100 >= 0) {
        return "C" + toRoman(num - 100);   
    }
    else if (num - 90 >= 0) {
        return "XC" + toRoman(num - 90);
    }
    else if (num - 50 >= 0) {
        return "L" + toRoman(num - 50);
    }
    else if (num - 40 >= 0) {
        return "XL" + toRoman(num - 40);
    }
    else if (num - 10 >= 0) {
        return "X" + toRoman(num - 10);
    }
    else if (num - 9 >= 0) {
        return "IX" + toRoman(num - 9);
    }
    else if (num - 5 >= 0) {
        return "V" + toRoman(num - 5);
    }
    else if (num - 4 >= 0) {
        return "IV" + toRoman(num - 4);
    }
    else if (num - 1 >= 0) {
        return "I" + toRoman(num - 1);
    }
    else return "";
}

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    
    int number;
    while (file >> number) {
        cout << toRoman(number) << endl;
    }
}