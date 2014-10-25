// https://www.codeeval.com/open_challenges/91/

#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        double value;
        vector<double> values;
        while (ss >> value) {
            values.push_back(value);
        }
        sort(values.begin(), values.end());
        cout << setprecision(3) << fixed;
        for (vector<double>::iterator it = values.begin(); it != values.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }
}