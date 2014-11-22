//
//  datarecovery.cpp
//  codeval1
//
//  Created by Malcolm Crum on 5/13/14.
//
//

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> splitString(string str) {
    vector<string> vec;
    stringstream ss(str);
    string s;
    while (ss >> s) {
        vec.push_back(s);
    }
    return vec;
}

vector<int> splitIntString(string str) {
    vector<int> vec;
    stringstream ss(str);
    int i;
    while (ss >> i) {
        vec.push_back(i);
    }
    return vec;
} 

int main(int argc, char** argv) {
    ifstream fileInput;
    fileInput.open(argv[1]);

    string line;
    while (getline(fileInput, line)) {
        
        string wordString = line.substr(0, line.find(';'));
        vector<string> words = splitString(wordString);
        string orderString = line.substr(line.find(';') + 1);
        vector<int> order = splitIntString(orderString);
        
        vector<string> orderedWords(order.size() + 1);
        for (int i = 0; i < order.size(); ++i) {
            int index = order[i] - 1;
            //cout << words[i] << " ";
            orderedWords[index] = words[i];
        }
        
        int missingIndex = 1;
        for (int i = 1; i < words.size() + 1; ++i) {
            if (find(order.begin(), order.end(), i) == order.end()) {
                missingIndex = i;
                break;
            }
        }
        orderedWords[missingIndex - 1] = words.back();
        
        for (vector<string>::iterator it = orderedWords.begin(); it != orderedWords.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }
}