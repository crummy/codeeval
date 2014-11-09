// https://www.codeeval.com/open_challenges/65/

#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

class LetterGrid {
public:
    bool hasString(string str);
private:
    static const int width = 4;
    static const int height = 3;
    static const char* grid;
    bool searchString(string str, char* visited, int x, int y);
    char at(int x, int y);
};

const char* LetterGrid::grid = "ABCESFCSADEE";

bool LetterGrid::hasString(string str) {
    for (int x = 0; x < this->width; ++x) {
        for (int y = 0; y < this->height; ++y) {
            char visited[12];
            if (searchString(str, visited, x, y)) {
                return true;
            }
        }
    }
    return false;
}

char LetterGrid::at(int x, int y) {
    return this->grid[y * this->width + x];
}

bool LetterGrid::searchString(string str, char* visited, int x, int y) {
    if (str.length() == 0) {
        return true;
    }
    else if (x < 0 || x > this->width) {
        return false; // OOB
    }
    else if (y < 0 || y > this->height) {
        return false; // OOB
    }
    else if (this->at(x, y) != str.at(0)) {
        return false; // letter does not match
    }
    else if (visited[y * this->width + x] == 'X') {
        return false; // we've already been here
    }
    //cout << "Found " << str.at(0) << " at " << x << "," << y << endl;
    string restOfString = str.substr(1);
    char newVisited[12];
    strcpy(newVisited, visited);
    newVisited[y * this->width + x] = 'X';
    if (searchString(restOfString, newVisited, x + 1, y)) {
        return true;
    }
    else if (searchString(restOfString, newVisited, x - 1, y)) {
        return true;
    }
    else if (searchString(restOfString, newVisited, x, y + 1)) {
        return true;
    }
    else if (searchString(restOfString, newVisited, x, y - 1)) {
        return true;
    }
    return false;
}

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    
    string word;
    LetterGrid grid;
    while (file >> word) {
        if (grid.hasString(word)) {
            cout << "True" << endl;
        }
        else {
            cout << "False" << endl;
        }
    }
    return 0;
}