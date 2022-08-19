#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <exception>
#include "ListNode.h"
using namespace std;


///doublylinked list class
template <typename T>
class DoublyLinkedList{
    private:
        ListNode *front;
        ListNode *back;
        unsigned int size;
    public:
        DoublyLinkedList();
        ~DoublyLinkedList();

        void insertFront(T d);
        void insertBack(char d);
        T removeFront(); // temporarily removing as a character. Soon replace char with T for template
        T removeBack();
        T removeNode(char value);
        T find(char value);
        bool isEmpty();
        unsigned int getSize();
        void printList(bool isPrintLink);
};


#endif