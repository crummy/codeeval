// https://www.codeeval.com/open_challenges/98/

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main(int argc, char** argv) {
    FILE *file;
    file = fopen(argv[1], "r");
    float x1, y1, r, x2, y2;
    while (fscanf(file, " Center: (%f, %f); Radius: %f; Point: (%f, %f)", &x1, &y1, &r, &x2, &y2) != -1) {
        double distance = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
        if (distance < r) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
    }
}