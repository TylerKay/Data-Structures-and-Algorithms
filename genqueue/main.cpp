#include "GenQueue.h"

int main(int argc, char **argv){
    GenQueue *myQueue = new GenQueue(10);

    try {
        // myQueue -> insert('F');
        // myQueue -> insert('O');
        // myQueue -> insert('O');
        // myQueue -> insert('B');
        // myQueue -> insert('A');
        // myQueue -> insert('R');

        myQueue-> printArray();
        myQueue-> enqueue('F');
        myQueue-> enqueue('O');
        myQueue-> enqueue('O');
        myQueue-> enqueue('B');
        myQueue-> enqueue('A');
        myQueue-> enqueue('A');
        
        cout << "PEEK: " << myQueue->peek() << endl;
        cout << "REMOVE: " << myQueue->remove() << endl;
        cout << "SIZE: " << myQueue->getSize() << endl;

        while(!myQueue->isEmpty()){
            cout << "REMOVE: " << myQueue->remove() << endl;
        }
        cout << "AFTER LOOP SIZE: " << myQueue-> getSize() << endl;

    }
    catch(runtime_error &excpt){
        cout << excpt.what() << endl;
    }

    delete myQueue;
    return 0;
}