// https://www.codeeval.com/open_challenges/153/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    int doorCount, iterations;
    while (file >> doorCount >> iterations) {
        vector<bool> locked(doorCount, false);

        // initial m-1 iterations: lock every 2nd, swap every 3rd
        for (int iteration = 0; iteration < iterations - 1; ++iteration) {
            for (int doorIndex = 0; doorIndex < doorCount; ++doorIndex) {
                if ((doorIndex+1) % 2 == 0) {
                    locked[doorIndex] = true;
                }
                if ((doorIndex+1) % 3 == 0) {
                    locked[doorIndex] = !locked[doorIndex];
                }
            }
        }
        
        // final iteration
        locked.back() = !locked.back();
        
        // count em up
        int totalUnlocked = 0;
        for (vector<bool>::iterator door = locked.begin(); door != locked.end(); ++door) {
            if (*door == false) {
                totalUnlocked++;
            }
        }
        cout << totalUnlocked << endl;
    }
}