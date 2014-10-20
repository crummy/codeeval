// https://www.codeeval.com/open_challenges/100/

#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    ifstream file;
    file.open(argv[1]);
    int value;
    while (file >> value) {
        if (value % 2 == 0) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
}