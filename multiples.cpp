//
//  multiples.cpp
//  codeval1
//
//  Created by Malcolm Crum on 7/7/14.
//
//

#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char **argv) {
    ifstream fileInput;
    fileInput.open(argv[1]);
    int x, n;
    string curr;
    while (getline(fileInput, curr, ',')) {
        x = stoi(curr);
        getline(fileInput, curr, '\n');
        n = stoi(curr);
        int answer = n;
        while (x > answer) {
            answer = answer + n;
        }
        cout << answer << endl;
    }
}