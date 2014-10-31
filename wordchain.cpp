// https://www.codeeval.com/open_challenges/135/

#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

int longestChain(vector<string> words, string word) {

    // create a new vector, a copy of words except without word
    vector<string> remainingWords;
    for (int j = 0; j < words.size(); ++j) {
        if (words[j].compare(word) != 0) {
            remainingWords.push_back(words[j]);
        }
    }
    
    
    int longest = 1;
    for (int j = 0; j < remainingWords.size(); ++j) {
        if (word.at(word.length()-1) == remainingWords[j].at(0)) {
            int chain = 1 + longestChain(remainingWords, remainingWords[j]);
            if (chain > longest) {
                longest = chain;
            }
        }
    }
    
    return longest;
}

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    
    string line;
    while (getline(file, line)) {
        
        vector<string> words;
        string word;
        stringstream ss(line);
        while (getline(ss, word, ',')) {
            words.push_back(word);
        }
        
        int longest = 0;
        for (vector<string>::iterator it = words.begin(); it != words.end(); ++it) {
            int chain = longestChain(words, *it);
            if (chain > longest) {
                longest = chain;
            }
        }
        
        if (longest > 1) {
            cout << longest << endl;
        } else {
            cout << "None" << endl;
        }
    }
}