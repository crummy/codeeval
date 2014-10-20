/*
 * =====================================================================================
 *
 *       Filename:  bitpositions.c
 *
 *    Description:  CodeEval solution to https://www.codeeval.com/open_challenges/19/
 *
 *        Version:  1.0
 *        Created:  10/18/14 08:29:56
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Malcolm Crum, crummynz@gmail.com
 *
 * =====================================================================================
 */

#include	<sstream>
#include	<stdlib.h>
#include	<iostream>
#include	<fstream>
#include	<string>
#include	<vector>
#include    <cmath>

using namespace std;

int main(int argc, char** argv) {
    ifstream inputFile(argv[1]);
    string line;
    while (getline(inputFile, line)) {
        if (line.length() == 0) {
            break;
        }
        stringstream ss(line);
        string value;
        vector<int> values;
        while (getline(ss, value, ',')) {
            values.push_back(atoi(value.c_str()));
        }
        int n = values[0];
        int p1 = pow(2, values[1] - 1);
        int p2 = pow(2, values[2] - 1);
        bool p1BitsZero = ((n & p1) == 0);
        bool p2BitsZero = ((n & p2) == 0);
        //cout << "n: " << n << ", p1: " << p1 << ", p2: " << p2 << endl;
        //cout << "n[p1] = " << p1BitsZero << ", n[p2] = " << p2BitsZero << endl;
        if ((p1BitsZero && p2BitsZero) ||
            (!p1BitsZero && !p2BitsZero)) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
    }
    return 0;
}
