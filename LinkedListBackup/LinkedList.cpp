#include "LinkedList.h"

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(){
    front = NULL;
    back = NULL;
    size = 0;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList(){
    //guess what??? build some character and research
    ListNode *node = front;
    ListNode *nodeToDelete = front;
    while (node != NULL){
        nodeToDelete = node->next;
        delete node;
        node = nodeToDelete;
    }
}

template <typename T>
void DoublyLinkedList<T>::insertFront(T d){
    ListNode * node = new ListNode(d);

    if(isEmpty()){
        back = node;
    }
    else{
        //it's not empty
        node->next = front;
        front->prev = node;
    }
    front = node;
    ++size;
}
template <typename T>
void DoublyLinkedList<T>::insertBack(char d){
    ListNode *node = new ListNode(d);

    if(isEmpty()){
        front = node;
    }
    else{
        node->prev = back;
        back->next = node;
    }
    back = node;
    ++size;
}

template <typename T>
T DoublyLinkedList<T>::removeFront(){
    if(isEmpty()){
        throw runtime_error("list is empty!");
    }

    ListNode *temp = front;

    if(front->next == NULL){
        back = NULL;
    }
    else{
        //more than one node in the list
        front->next->prev = NULL;
    }
    front = front->next;
    temp->next = NULL;
    char data = temp->data;
    --size;
    delete temp;
    return data;
}

template <typename T>
T DoublyLinkedList<T>::removeBack(){
    if(isEmpty()){
        throw runtime_error("list is empty");
    }

    ListNode *temp = front;

    if(back->prev = NULL){
        //only node in the list
        front = NULL;
    }
    else{
        //more than one node in the list
        back->prev->next = NULL;
    }
    back = back->prev;
    temp->prev = NULL;
    char data = temp->data;
    --size;
    delete temp;
    return data;
}

template <typename T>
T DoublyLinkedList<T>::find(char value){
    int pos = -1;
    ListNode *curr = front;

    while(curr != NULL){
        ++pos;
        if(curr->data == value)
            break;
        
        curr = curr->next;
    }
    //checks if curr is NULL which signifies value not in Linked List
    if(curr == NULL)
        pos = -1;

    return pos;
}

template <typename T>
T DoublyLinkedList<T>::removeNode(char value){
    if(isEmpty()){
        throw runtime_error("list is empty!");
    }

    //we could leverage the find method

    ListNode *curr = front;
    while(curr->data != value){
        curr = curr->next;

        if(curr == NULL)    
            return -1;
    }
    //but if we make it here, we found the value
    //we found it , let's proceed to remove it

    if(curr != front && curr != back){
        //it's in between front and back
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }

    if(curr == front){
        front = curr->next;
        front->prev = NULL;
    }

    if(curr == back){
        back = curr->prev;
        back->next = NULL;
    }

    curr->next = NULL;
    curr->prev = NULL;
    char data = curr->data;
    --size;
    delete curr;

    return data;   
}
template <typename T>
unsigned int DoublyLinkedList<T>::getSize(){
    return size;
}

template <typename T>
bool DoublyLinkedList<T>::isEmpty(){
    return (size == 0);
}

template <typename T>
void DoublyLinkedList<T>::printList(bool printLink)
{
    ListNode *curr = front;
    while(curr != 0){
       if(curr == front){
         cout << "{FRONT}: ";
       }
       else if(curr == back){
         cout << "{REAR}: ";
       }
       if(printLink)
        cout << "[ PREV: "<< curr->prev << " || " << curr->data << " || NEXT: "<< curr->next << " ] ";
      else
        cout << "[ " << curr->data << " ] ";

       curr = curr->next;
       if(curr != 0){
         cout << " <==> ";
       }
    }
    cout << endl;
}
