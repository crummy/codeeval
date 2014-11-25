// https://www.codeeval.com/open_challenges/124/

#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

struct cityComparison {
    inline bool operator() (const pair<string, int> &left, const pair<string, int> &right) {
        return left.second < right.second;
    }
};

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string destinationString;    
        vector<pair<string, int> > cities;
        while(getline(ss, destinationString, ';')) {
            if (destinationString.at(0) == ' ') {
                destinationString = destinationString.substr(1);
            }
            if (destinationString.at(0) == '\n') {
                destinationString = destinationString.substr(1);
            }
            
            pair<string, int> city;
            city.first = destinationString.substr(0, destinationString.find(','));
            
            stringstream distanceSS(destinationString.substr(destinationString.find(',') + 1));
            int distance;
            distanceSS >> distance;
            city.second = distance;
            
            cities.push_back(city); 
        }
        
        sort(cities.begin(), cities.end(), cityComparison());
    
        int lastDistance = 0;
        for (vector<pair<string, int> >::iterator it = cities.begin(); it != cities.end(); ++it) {
            pair<string, int> city = *it;
            cout << city.second - lastDistance;
            if (it != --cities.end()) {
                cout << ",";
            }
            lastDistance = city.second;
        }
        cout << endl;
    }
    return 0;
}