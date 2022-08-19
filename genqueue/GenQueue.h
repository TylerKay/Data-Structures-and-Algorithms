#ifndef GENQUEUE_H
#define GENQUEUE_H
#include <iostream>

using namespace std;

// array based Queue
class GenQueue {
    public:
        GenQueue(); // default constructor
        GenQueue(int maxSize); // overloaded constructor
        ~GenQueue(); // destructor

        // core functions
        void insert(char d); // aka enqueue
        char remove(); // aka de-queue
        
        //aux functions
        char peek();
        bool isFull();
        bool isEmpty();
        unsigned int getSize(); //unsigned means no negative
        void printArray();
        void enqueue(char d); // Pre-queue



    private:
        int mSize;
        int front;
        int rear;
        unsigned int numElements;
        char *myQueue;

};

#endif