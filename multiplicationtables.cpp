//
//  multiplicationtables.cpp
//  codeval1
//
//  Created by sonossqa on 5/9/14.
//
//

#include <iostream>

int main() {
    for (int i = 1; i <= 12; i++) {
        for (int j = 1; j <= 12; j++) {
            printf("%4d", i * j);
        }
        printf("\n");
    }
}