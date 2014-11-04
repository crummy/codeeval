// https://www.codeeval.com/open_challenges/89/

#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int calcMaxSum(vector<vector<int> >&sums, vector<vector<int> > &rows, int row, int index) {
    if (row == rows.size() - 1) {
        return rows[row][index];
    }
    else {
        int leftMax = sums[row+1][index];
        int rightMax = sums[row+1][index+1];
        if (leftMax > rightMax) {
            return rows[row][index] + leftMax;
        }
        else {
            return rows[row][index] + rightMax;
        }
    }
}

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    
    // read the triangle.
    // each row is stored in a separate vector, each row an element longer than the last.
    // all the rows are stored in the rows vector.
    vector<vector<int> > rows;
    string line;
    while (getline(file, line)) {
        
        stringstream ss(line);
        int value;
        vector<int> row;
        while (ss >> value) {
            row.push_back(value);
        }
        rows.push_back(row);
    
    }
    
    // build an equivalently sized triangle, but where every node is the sum of every
    // lower node
    // actually it's a square... for easier initialization.
    // but I treat it as a triangle.
    vector<vector<int> > sums(rows.size(), vector<int>(rows.size(), 0));
    for (int row = rows.size() - 1; row >= 0; --row) {
        for (int index = 0; index < rows[row].size(); ++index) {
            sums[row][index] = calcMaxSum(sums, rows, row, index);
        }
    }
    
    int maxSum = sums[0][0];
    cout << maxSum << endl;
    return 0;
}