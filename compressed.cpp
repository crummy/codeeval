// https://www.codeeval.com/open_challenges/128/

#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    
    string line;
    while (getline(file, line)) {
        
        stringstream ss(line);
        int readNumber;
        ss >> readNumber;
        int readCount = 1;
        int newInput;
        while (ss >> newInput) {
            
            if (newInput != readNumber) {
                cout << readCount << " " << readNumber << " ";
                readNumber = newInput;
                readCount = 1;
            }
            else {
                readCount++;
            }
            
        }
        cout << readCount << " " << readNumber << " " << endl;
    }
    return 0;
}