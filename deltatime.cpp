// https://www.codeeval.com/open_challenges/166/

#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    
    string line;
    while (getline(file, line)) {
        
        int hourA = atoi(line.substr(0,2).c_str());
        int minA  = atoi(line.substr(3,5).c_str());
        int secA  = atoi(line.substr(6,8).c_str());
        int totalSecondsA = secA + 60 * minA + 60 * 60 * hourA;
        
        int hourB = atoi(line.substr(9,11).c_str());
        int minB  = atoi(line.substr(12,14).c_str());
        int secB  = atoi(line.substr(15,17).c_str());
        int totalSecondsB = secB + 60 * minB + 60 * 60 * hourB;
        
        int difference = abs(totalSecondsA - totalSecondsB);
        
        int sec   = difference % 60;
        int min   = (difference - sec) / 60 % 60;
        int hour  = (difference - sec - (min * 60)) / (60*60);
        
        cout << setfill('0') << setw(2) << hour << ":"
             << setw(2) << min << ":"
             << setw(2) << sec << endl;
    }
}