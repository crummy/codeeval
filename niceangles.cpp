// https://www.codeeval.com/open_challenges/160/

#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    double angle;
    while (file >> angle) {
        int deg, hour, min;
        deg = (int)angle;
        angle -= deg;
        hour = angle * 60;
        angle -= (double)hour / 60;
        min = angle * 60 * 60;
        
        cout << deg << ".";
        cout << setw(2) << setfill('0') << hour << "'";
        cout << setw(2) << setfill('0') << min << "\"" << endl;
    }
}