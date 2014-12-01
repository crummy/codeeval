// https://www.codeeval.com/open_challenges/125/
// cheated on this one...

#include <fstream>
#include <iostream>
#include <bitset>

using namespace std;

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    
    int N;
    while (file >> N) {
        
        bitset<32> bits(N);
        long long ones = 0; // int fails half the tests. make it long long for good measure.
                            // int works on my VM actually, but not on codeeval apparently.
        for (int i = 0; i < bits.size(); ++i) {
            if (bits[i] == 1) {
                ones++;
            }
        }
        
        int answer = ones % 3;
        
        cout << answer << endl;
    }
    
    return 0;
}