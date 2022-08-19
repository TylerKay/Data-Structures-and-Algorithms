#include "bst.h"
#include <iostream>
using namespace std;

int main(){
    BST<int> *b = new BST<int>;
    b->insert(1);
    b->insert(2);
    b->insert(10);
    b->insert(6);
    b->insert(36);
    b->printNodes();

    delete b;
    return 0;
}