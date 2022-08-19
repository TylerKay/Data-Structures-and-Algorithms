#ifndef GENSTACK_H
#define GENSTACK_H
#include <iostream>

using namespace std;

class GenStack{
    public:
        GenStack(); // default constructor
        GenStack(int maxSize); // overloaded constructor
        ~GenStack(); // Destructor

    // core functions
        // For this example, we will use array of characters

        void push(char data);
        char pop();
        char peek(); // aka top()

        // aux functions
        bool isEmpty();
        bool isFull();
        int getSize();
    
    private:
        char *myArray;
        int top; // keep track of where we are in the array and the top of the stack
        int mSize; // max size
};

#endif