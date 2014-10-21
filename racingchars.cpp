// https://www.codeeval.com/open_challenges/136/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int findNextCheckpoint(int position, string line, int width) {
    if (position >= 1 && (line.at(position - 1) == 'C')) {
        return position - 1;
    } else if (line.at(position) == 'C') {
        return position;
    } else if (position < width - 1 && (line.at(position + 1) == 'C')) {
        return position + 1;
    }
    return -1; // no checkpoint found
}

int findNextTrack(int position, string line, int width) {
    if (position >= 1 && (line.at(position - 1) == '_')) {
        return position - 1;
    } else if (line.at(position) == '_') {
        return position;
    } else if (position < width - 1 && (line.at(position + 1) == '_')) {
        return position + 1;
    }
    return -1; // no track found?????
}

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    if (!file.is_open()) {
        return 1;
    }
    string line;
    vector<string> lines;
    while (file >> line) {
        lines.push_back(line);
    }
    
    int width = lines[0].length();
    int lastPosition = lines[0].find('_'); // get initial position of racer
    
    for (int i = 0; i < lines.size(); ++i) {
        string line = lines[i];
        
        int position = findNextCheckpoint(lastPosition, line, width);
        if (position == -1) {
            position = findNextTrack(lastPosition, line, width);
        }
        
        if (position < lastPosition)
            line.at(position) = '/';
        if (position == lastPosition)
            line.at(position) = '|';
        if (position > lastPosition)
            line.at(position) = '\\';
        cout << line << endl;
        
        lastPosition = position;
    }
}