#include <iostream>
#include "SingleLinkedList.h"

using namespace std;

int main(){
    SingleLinkedList *s = new SingleLinkedList();
    s->insertFront(1);
    s->insertFront(2);
    s->insertFront(3);
    s->insertFront(4);

    // s->deleteAtPos(1);

    s->print();

    delete s;

    return 0;
}