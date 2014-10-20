// https://www.codeeval.com/open_challenges/26/

#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    ifstream in(argv[1], ifstream::ate | ifstream::binary);
    cout << in.tellg() << endl;
}