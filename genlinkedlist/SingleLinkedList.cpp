#include "SingleLinkedList.h"

SingleLinkedList::SingleLinkedList(){
    front = NULL;
    back = NULL;
    size = 0;
}

SingleLinkedList::~SingleLinkedList(){
    delete front;
    delete back;
    // build some character
}

void SingleLinkedList::insertFront(int d){
    ListNode *node = new ListNode(d);

    if (isEmpty()){
        back = node;
    }
    node->next = front;
    front = node;
    size++;
}

void SingleLinkedList::insertBack(int d){
    ListNode *node = new ListNode(d);

    if (isEmpty()){
        front = node;
    }

    else {
        back->next = node;
    }
    
    back = node;
    size++;
}

bool SingleLinkedList::isEmpty(){
    return size == 0;
}

int SingleLinkedList::removeFront(){
    if (isEmpty()){
        cout << "List is empty" << endl;
        return -1;
    }

    // finish off if not empty and size == 1. 
    
    int temp = front->data;
    ListNode *ft = front; // ft stands for front temp. Removing front means that there needs to be a new front.
    
    front = front->next;
    ft->next = NULL;
    delete ft;
}

// int SingleLinkedList::removeBack(){

// }

int SingleLinkedList::find(int value){
    int pos = -1; // set position equal to -1

    ListNode *curr = front;
    while (curr != NULL){
        ++pos;
        if (curr->data == value){
            break;
        }
        curr = curr->next; // curr is on the stack, so we don't have to garbage collect.
    }

    // check if we found the value
    if (curr == NULL){
        pos = -1;
    }

    return pos;
}

int SingleLinkedList::deleteAtPos(int pos){
    
    // check if empty and check if value exist
    if (isEmpty()){
        cout << "List is empty" << endl;
        return -1;
    }

    int idx = 0;
    ListNode *curr = front;
    ListNode *prev = front;

    while (idx != pos){
        prev = curr;
        curr = curr->next;
    }

    // we found it, lets proceed to delete
    prev->next = curr->next;
    curr->next = NULL;
    int d = curr->data;
    size--;

    delete curr;
    return d;
}


void SingleLinkedList::print(){
	ListNode* curr = new ListNode;

	curr = front;

	while (curr != nullptr){
		cout << curr->data << endl;
		curr = curr->next;
	}

    delete curr;
}