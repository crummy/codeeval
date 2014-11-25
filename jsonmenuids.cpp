// https://www.codeeval.com/open_challenges/102/

#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

int countIdsWithLabels(string line) {
    // we don't need no stinking JSON parser
    int sumOfIds = 0;
    string currentLine = line.substr(0, line.length() - 1);
    const string labelTag = "\"label\": ";
    const string idTag = "\"id\": "; 
    while (currentLine.find(labelTag) != -1) {
        
        currentLine = currentLine.substr(0, currentLine.rfind(labelTag));
        int idIndex = currentLine.rfind(idTag);
        int commaIndex = currentLine.rfind(',');
        
        string numberString = currentLine.substr(idIndex + idTag.length(), commaIndex);
        int number = atoi(numberString.c_str());
        sumOfIds += number;
        
        currentLine = currentLine.substr(0, idIndex);
        
    }
    return sumOfIds;
}

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    
    string line;
    while (getline(file, line)) {
        if (line.length() > 0) {
            cout << countIdsWithLabels(line) << endl;
        }
    }
    return 0;
}