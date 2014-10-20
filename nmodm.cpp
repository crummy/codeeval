//
//  nmodm.cpp
//  codeval1
//
//  Created by sonossqa on 7/7/14.
//
//

#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char **argv) {
    ifstream fileInput;
    fileInput.open(argv[1]);
    int m, n;
    string curr;
    while (getline(fileInput, curr, ',')) {
        n = stoi(curr);
        getline(fileInput, curr, '\n');
        m = stoi(curr);
        int remainder = n;
        while (remainder >= m) {
            remainder = remainder - m;
        }
        cout << remainder << endl;
    }
}