// https://www.codeeval.com/open_challenges/161/

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

#define ROWS 100
#define COLUMNS 100

int countNeighbours(vector<vector<char> > life, int row, int col) {
    int topleft = 0, top = 0, topright = 0, right = 0, botright = 0, bot = 0, botleft = 0, left = 0;
    if (row > 0) {
        if (col > 0) {
            if (life[row-1][col-1] == '*') {
                topleft++;
            }
        }
        if (life[row-1][col] == '*') {
            left++;
        }
        if (col < COLUMNS - 1) {
            if (life[row-1][col+1] == '*') {
                botleft++;
            }
        }
    }
    if (row < ROWS - 1) {
        if (col > 0) {
            if (life[row+1][col-1] == '*') {
                topright++;
            }
        }
        if (life[row+1][col] == '*') {
            right++;
        }
        if (col < COLUMNS - 1) {
            if (life[row+1][col+1] == '*') {
                botright++;
            }
        }
    }
    if (col > 0) {
        if (life[row][col-1] == '*') {
            top++;
        }
    }
    if (col < COLUMNS - 1) {
        if (life[row][col+1] == '*') {
            bot++;
        }
    }
    return topleft + top + topright + right + botright + bot + botleft + left;
}

void printLife(vector<vector<char> > &life) {
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLUMNS; ++col) {
            cout << life[row][col];
        }
        cout << endl;
    }
    cout << endl;
}


void playLife(vector<vector<char> > &life, int iterations) {
    for (int iteration = 0; iteration < iterations; ++iteration) {
        vector<vector<char> > newLife(ROWS, vector<char>(COLUMNS, 0));
        for (int row = 0; row < ROWS; ++row) {
            for (int col = 0; col < COLUMNS; ++col) {
                char cell = life[row][col];
                int neighbours = countNeighbours(life, row, col);
                if (cell == '.' && neighbours == 3) {
                    newLife[row][col] = '*';
                }
                else if (cell == '*' && neighbours < 2) {
                    newLife[row][col] = '.';
                }
                else if (cell == '*' && neighbours <= 3) {
                    newLife[row][col] = '*';
                }
                else {
                    newLife[row][col] = '.';
                }
            }
        }
        life = newLife;
    }
}

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    
    vector<vector<char> > life(ROWS, vector<char>(COLUMNS, 0));
    int row = 0;
    string line;
    while (getline(file, line)) {
        for (int col = 0; col < line.length(); ++col) {
            life[row][col] = line.at(col);
        }
        row++;
    }
    
    playLife(life, 10);
    
    printLife(life);
    
    return 0;
}