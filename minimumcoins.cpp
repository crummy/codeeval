// https://www.codeeval.com/open_challenges/74/

#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    int money;
    while (file >> money) {
        int ones = 0, threes = 0, fives = 0;
        fives = money / 5;
        money = money % 5;
        threes = money / 3;
        money = money % 3;
        ones = money;
        cout << fives + threes + ones << endl;
    }
}