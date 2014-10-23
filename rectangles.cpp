// https://www.codeeval.com/open_challenges/70/

#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Box {
public:
    int x1, y1, x2, y2;
    Box(int x1, int y1, int x2, int y2) {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
    }
    friend ostream& operator<<(ostream&os, const Box& box) {
        os << "(" << box.x1 << "," << box.y1 << "),(" << box.x2 << "," << box.y2 << ")";
        return os;
    }
};

bool boxesOverlap(Box b1, Box b2) {
    if (b1.x1 > b2.x2) {
        return false; 
    }
    if (b1.x2 < b2.x1) {
        return false; 
    }
    if (b1.y1 < b2.y2) {
        return false;
    }
    if (b1.y2 > b2.y1) {
        return false;
    }
    return true;
}

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    string line;
    while (getline(file, line)) {
        
        vector<int> coords;
        stringstream ss(line);
        
        for (int i = 0; i < 4; i++) {
            int coord;
            ss >> coord;
            coords.push_back(coord);
            
            if (ss.peek() == ',')
                ss.ignore();
        }

        Box box1 = Box(coords[0], coords[1], coords[2], coords[3]);
        coords.clear();
        
        for (int i = 0; i < 4; i++) {
            int coord;
            ss >> coord;
            coords.push_back(coord);
            
            if (ss.peek() == ',')
                ss.ignore();
        }
        
        Box box2 = Box(coords[0], coords[1], coords[2], coords[3]);
        
        if (boxesOverlap(box1, box2))
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
}