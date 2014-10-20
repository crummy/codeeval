//
//  stack.cpp
//  codeval1
//
//  Created by sonossqa on 5/9/14.
//
//

#include <fstream>
#include <iostream>
#include <assert.h>
using namespace std;

class IntStack {
    int size;
    int max;
    int *elements;
public:
    IntStack();
    ~IntStack();
    int pop();
    void push(int value);
    bool isEmpty();
};

IntStack::IntStack() {
    size = 0;
    max = 2;
    elements = (int *)malloc(max * sizeof(int));
}

IntStack::~IntStack() {
    free(elements);
}

int IntStack::pop() {
    assert(size > 0);
    int poppedElement = elements[size - 1];
    size--;
    return poppedElement;
}

void IntStack::push(int value) {
    if (size >= max) {
        max *= 2;
        int *newElements = (int *)malloc(max * sizeof(int));
        for (int i = 0; i < size; i++) {
            newElements[i] = elements[i];
        }
        int *oldElements = elements;
        elements = newElements;
        free(oldElements);
    }
    size++;
    elements[size - 1] = value;
}

bool IntStack::isEmpty() {
    return (size == 0);
}

int main(int argc, char** argv) {
    ifstream fileInput;
    fileInput.open(argv[1]);
    
    IntStack *stack = new IntStack();
    int value;
    while (fileInput.peek() != EOF) {
        while ((fileInput.peek() != '\n') && (fileInput >> value)) {
            stack->push(value);
        }
        fileInput.get(); // chomp the newline
        while (!stack->isEmpty()) {
            cout << stack->pop() << " ";
            if (!stack->isEmpty()) {
                stack->pop();
            }
        }
        cout << endl;
    }

}