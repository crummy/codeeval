// https://www.codeeval.com/browse/170/

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
        
        int max;
        ss >> max;
        int min = 0;
        
        string response;
        int guess;
        
        do  {
            ss >> response;
            guess = min + (max - min - 1) / 2 + 1;
            //cout << "guess: " << guess << " in [" << min << "," << max << "]: " << response << endl;
            if (response == "Higher") {
                min = guess + 1;
            }
            else if (response == "Lower") {
                max = guess - 1;
            }
        } while (response != "Yay!");
        
        cout << guess << endl;
    }
}