#include "mydemo.h"

MySimpleClass::MySimpleClass(){
    foo = 0;
    bar = 0;
}

MySimpleClass::~MySimpleClass(){
    cout << "bye" << endl;
}

int MySimpleClass::countVowels(string userInput){
    int count = 0;
    char c = '\0';

    for (int i = 0; i < userInput.size(); ++i){
        c = tolower(userInput[i]);
        if ((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u')) {
            count++;
        }
    }
    return count;
}