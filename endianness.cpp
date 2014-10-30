// https://www.codeeval.com/open_challenges/15/

#include <iostream>

int main() {
    int num = 1;
    if(*(char *)&num == 1) {
        std::cout << "LittleEndian" << std::endl;
    }
    else {
        std::cout << "BigEndian" << std::endl;
    }
}