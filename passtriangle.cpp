// https://www.codeeval.com/open_challenges/89/

#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int findMaxSum(vector<vector<int> > rows, int row, int index) {
    int value = rows[row][index];
    if (row == rows.size() - 1) {
        return value;
    }
    int leftSum = value + findMaxSum(rows, row + 1, index);
    int rightSum = value + findMaxSum(rows, row + 1, index + 1);
    if (leftSum > rightSum) {
        return leftSum;
    } else {
        return rightSum;
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
    
    int maxSum = findMaxSum(rows, 0, 0);
    cout << maxSum << endl;
    return 0;
}