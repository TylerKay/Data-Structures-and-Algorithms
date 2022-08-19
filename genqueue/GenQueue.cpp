#include "GenQueue.h"
#include <exception>

GenQueue::GenQueue(){
    mSize = 128; //default size of queue;
    front = 0;
    rear = 0;
    numElements = 0;
    myQueue = new char[mSize];
}

GenQueue::GenQueue(int maxSize){
    mSize = maxSize; //default size of queue;
    front = 0;
    rear = 0;
    numElements = 0;
    myQueue = new char[mSize];
}

GenQueue::~GenQueue(){
    delete[] myQueue;
}

void GenQueue::insert(char d){
    if (isFull()){
        throw runtime_error("Queue is full");
    }

    myQueue[rear++] = d;
    rear %= mSize; // rear = rear % mSize;
    numElements++;
}

void GenQueue::enqueue(char d){
    if (isFull()){
        throw runtime_error("Priority Queue is full");
    }

    int i = numElements-1;
    while((i >= 0) && (d < myQueue[i])){
        myQueue[i+1] = myQueue[i];
        i--;   
    }
    myQueue[i+1] = d;
    numElements++;

} 


char GenQueue::remove(){
    if (isEmpty()){
        throw runtime_error("Queue is empty");
    }
    
    char c = '\0'; // initialize temporary variable c = null
    // c = myQueue[front++];
    c = myQueue[front];
    front++;
    front %= mSize;
    numElements--;
    return c;
}

char GenQueue::peek(){
    return myQueue[front];
}

bool GenQueue::isFull(){
    return numElements == mSize;
}

bool GenQueue::isEmpty(){
    return numElements == 0;
}

unsigned int GenQueue::getSize(){
    return numElements;
}


void GenQueue::printArray(){
  cout << "Q SIZE: " << getSize() << endl;
  cout << "FRONT: " << front <<endl;
  cout << "REAR: " << rear << endl;
  for(int i = 0; i < mSize; ++i){
     cout << "Q["<< i << "] " << myQueue[i];
     if(i != mSize-1){
       cout << " | ";
     }
  }
  cout << endl;
}

