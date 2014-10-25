// https://www.codeeval.com/open_challenges/152/

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    int age;
    while (file >> age) {
        if (age < 0 || age > 100) {
            cout << "This program is for humans" << endl;
        }
        else if (age <= 2) {
            cout << "Still in Mama's arms" << endl;
        }
        else if (age <= 4) {
            cout << "Preschool Maniac" << endl;
        }
        else if (age <= 11) {
            cout << "Elementary school" << endl;
        }
        else if (age <= 14) {
            cout << "Middle school" << endl;
        }
        else if (age <= 18) {
            cout << "High school" << endl;
        }
        else if (age <= 22) {
            cout << "College" << endl;
        }
        else if (age <= 65) {
            cout << "Working for the man" << endl;
        } else if (age <= 100) {
            cout << "The Golden Years" << endl;
        }
    }
}