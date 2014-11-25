// https://www.codeeval.com/open_challenges/87/

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Board {
private:
    static const int cols = 256;
    static const int rows = 256;
    vector<vector<int> > matrix; // cols then rows
    
public:
    Board() {
        matrix.resize(rows);
        for (vector<vector<int> >::iterator it = matrix.begin(); it != matrix.end(); ++it) {
            (*it).resize(cols);
        }
    }

    void SetRow(int row, int value) {
        for (int i = 0; i < cols; ++i) {
            matrix[i][row] = value;
        }
    }
    
    void SetCol(int col, int value) {
        for (int i = 0; i < rows; ++i) {
            matrix[col][i] = value;
        }
    }
    int QueryRow(int row) {
        int sum = 0;
        for (int i = 0; i < cols; ++i) {
            sum += matrix[i][row];
        }
        return sum;
    }
    int QueryCol(int col) {
        int sum = 0;
        for (int i = 0; i < rows; ++i) {
            sum += matrix[col][i];
        }
        return sum;
    }
};

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    
    Board board = Board();
    
    string line;
    while (getline(file, line)) {
        
        stringstream liness(line);
        string command;
        liness >> command;
        vector<int> args;
        int arg;
        while (liness >> arg) {
            args.push_back(arg);
        }
        
        if (command == "SetCol") {
            board.SetCol(args[0], args[1]);
        }
        else if (command == "SetRow") {
            board.SetRow(args[0], args[1]);
        }
        else if (command == "QueryCol") {
            cout << board.QueryCol(args[0]) << endl;
        }
        else if (command == "QueryRow") {
            cout << board.QueryRow(args[0]) << endl;
        }
    }
    return 0;
}