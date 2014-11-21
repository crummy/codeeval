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
#include <string>
using namespace std;

int main(int argc, char** argv) {
    ifstream fileInput;
    fileInput.open(argv[1]);

    //while (fileInput.peek() != EOF) {
        
        string word;
        vector<string> words;
        fileInput >> word;
        while (word.find(';') == string::npos) {
            words.push_back(word);
            fileInput >> word;
        }
        // the last "word" would normally get grabbed as 'word;9'.
        // special handling is required to split it into 'word' and '9'
        int semicolonIndex = word.find(';');
        words.push_back(word.substr(0, semicolonIndex));
        cout << "read " << words.size() << " words" << endl;
        
        for (int i = 0; i < words.size(); i++) {
            cout << words[i] << " ";
        }
        cout << endl;
        
        int value;
        vector<string> orderedWords;
        orderedWords.resize(words.size());
        // again, special handling required to get the number out of 'word;9'
        value = atoi(word.substr(semicolonIndex, word.size()).c_str());
        orderedWords[0] = words[value];
        for(int i = 1; fileInput.peek() != '\n'; i++) {
            fileInput >> value;
            cout << "words[" << value << "] = " << words[value] << endl;
            cout << "words[" << i << "] = " << words[i] << endl;
            orderedWords[value] = words[i];
        }
        
        for (int i = 0; i < orderedWords.size(); i++) {
            cout << orderedWords[i] << " ";
        }
        cout << endl;
    //}
}