#include "GenStack.cpp"

using namespace std;

int main(int argc, char **argv){
    GenStack *myStack = new GenStack(10);
    try{

        myStack->push('f');
        myStack->push('o');
        myStack->push('o');
        myStack->push('b');
        myStack->push('a');
        myStack->push('r');
        myStack->push('x');
        myStack->push('y');

        cout << "PEEK: " << myStack->peek() << endl;
        cout << "POP: " << myStack->pop() << endl;
        cout << "PEEK: " << myStack->peek() << endl;

        while(!myStack -> isEmpty()){
            cout << "POP: " << myStack->pop() << endl;
        }

        cout << "Size: " << myStack-> getSize() << endl;
        myStack->pop();
    }
    catch(runtime_error& excpt){
        cout << excpt.what()<< endl;
    }
    delete myStack;
    return 0;

}