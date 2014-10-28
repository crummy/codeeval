// https://www.codeeval.com/open_challenges/103/

#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    
    string line;
    while (getline(file, line)) {
        stringstream ss(line);

        vector<int> numbers(10, 0);
        vector<int> players(10, 0); // last player to select that number
        int number;
        int player = 0;
        while (ss >> number) {
            player++;
            numbers[number]++;
            players[number] = player;
        }
        
        bool foundPlayer = false;
        for (int numIndex = 0; numIndex < numbers.size(); ++numIndex) {
            if (numbers[numIndex] == 1) {
                foundPlayer = true;
                cout << players[numIndex] << endl;
                break;
            }
        }
        if (!foundPlayer) {
            cout << '0' << endl;
        }
    }
}