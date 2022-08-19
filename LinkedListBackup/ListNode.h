#include <iostream>
#include <exception>

using namespace std;

class ListNode{
    public:
        ListNode();
        ListNode(char d);
        ~ListNode();
        ListNode *next;
        ListNode *prev;
        char data;
};