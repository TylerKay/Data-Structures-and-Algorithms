#include "ListNode.h"

//implementation
ListNode::ListNode(){}

ListNode::ListNode(char d){
    data = d;
    next = NULL; // 0 nullptr
    prev = NULL;
}

ListNode::~ListNode(){
    //research
}