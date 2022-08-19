#include "GenStack.h"
#include <exception>

GenStack::GenStack(){
    mSize = 64; // default size of Stack
    top = -1; 
    myArray = new char[mSize];
}

GenStack::GenStack(int maxSize){
    mSize = maxSize; 
    top = -1; 
    myArray = new char[mSize];
}

GenStack::~GenStack(){
    delete[] myArray;
}


// void GenStack::push(char data){
//     //check if stack is full
//     if (isFull()){
//         throw runtime_error("stack is full");
//     }
//     myArray[++top] = data;
// }


// Dynamic stack. Resize if full.
void GenStack::push(char data){
    //check if stack is full
    if (isFull()){
        cout << "stack is resizing" << endl;
        char *temp = new char[2*mSize];
        for (int i = 0; i < mSize; ++i){
            temp[i] = myArray[i];
        }
        mSize *= 2; //mSize = mSize * 2
        delete[] myArray;
        myArray = temp;
    }
    myArray[++top] = data;
}

char GenStack::pop(){
    //make sure stack is not empty before proceeding
    if (isEmpty()){
        throw runtime_error("stack is empty, nothing to pop");
    }

    /* in multiple steps
        char temp = myArray[top];
        top --;
        return temp; */

    return myArray[top--];
}

char GenStack::peek(){
    // make sure stack is not empty before proceeding
    if (isEmpty()){
        throw runtime_error("stack is empty, nothing to peek");
    }
    return myArray[top];
}

bool GenStack::isFull(){
    return (top == mSize-1);
}

bool GenStack::isEmpty(){
    return (top == -1);
}

int GenStack::getSize(){
    return top + 1;
}