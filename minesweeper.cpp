// https://www.codeeval.com/open_challenges/79/

#include <fstream>
#include <iostream>
#include <vector>
#include <assert.h>
#include <stdio.h>

using namespace std;

class MineSweeper {
private:
    vector<vector<char> > board;
public:
    MineSweeper(int width, int height, string line) {
        assert(width * height == line.length());
        for (int x = 0; x < width; ++x) {
            vector<char> row;
            board.push_back(row);
            for (int y = 0; y < height; ++y) {
                char ch = line.at(x * height + y);
                board[x].push_back(ch);
            }
        }
    }
    void solve() {
        for (int x = 0; x < board.size(); ++x) {
            for (int y = 0; y < board[x].size(); ++y) {
                if (board[x][y] == '*') continue;   // already a bomb here, skip
                int topleft = 0, top = 0, topright = 0, right = 0,
                    bottomright = 0, bottom = 0, bottomleft = 0, left = 0;
                if (y > 0) { 
                    top = board[x][y-1]=='*' ? 1 : 0;
                }
                if (y < board[x].size()-1) {
                    bottom = board[x][y+1]=='*' ? 1 : 0;
                }
                if (x > 0) {
                    left = board[x-1][y]=='*' ? 1 : 0;
                    if (y > 0) {
                        topleft = board[x-1][y-1]=='*' ? 1 : 0;
                    }
                    if (y < board[x].size()-1) {
                        bottomleft = board[x-1][y+1]=='*' ? 1 : 0;
                    }
                }
                if (x < board.size()-1) {
                    right = board[x+1][y]=='*' ? 1 : 0;
                    if (y > 0) {
                        topright = board[x+1][y-1]=='*' ? 1 : 0;
                    }
                    if (y < board[x].size()-1) {
                        bottomright = board[x+1][y+1]=='*' ? 1 : 0;
                    }
                }
                board[x][y] = topleft + top + topright + right + bottomright + bottom + bottomleft + left + '0';
            }
        }
    }
    friend ostream& operator<<(ostream &os, const MineSweeper &ms) {
        for (int x = 0; x < ms.board.size(); ++x) {
            for (int y = 0; y < ms.board[x].size(); ++y) {
                os << ms.board[x][y];
            }
        }
        return os;
    }
};

int main(int argc, char** argv) {
    if (argc == 1) {
        cout << "Useage: " << argv[0] << "<inputfile.txt>" << endl;
        return 1;
    }
    FILE *inputFile = fopen(argv[1], "r");
    if (!inputFile) {
        cerr << "Error reading file" << endl;
        return 1;
    }
    char line[100];
    int width, height;
    while (fscanf(inputFile, " %d,%d;%s ", &width, &height, line) != EOF) {
        string lineString(line);
        MineSweeper ms(width, height, lineString);
        ms.solve();
        cout << ms << endl;
    }
    return 0;
}