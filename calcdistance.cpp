// https://www.codeeval.com/open_challenges/99/

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main(int argc, char** argv) {
    FILE *file;
    file = fopen(argv[1], "r");
    int x1, y1, x2, y2;
    while (fscanf(file, " (%d, %d) (%d, %d)", &x1, &y1, &x2, &y2) != -1) {
        double distance = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
        cout << distance << endl;
    }
}