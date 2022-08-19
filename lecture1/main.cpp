#include "mydemo.h"

int main(int argc, char **argv){

    MySimpleClass sc;
    MySimpleClass *sc2 = new MySimpleClass();

    cout << sc2 << endl;

    cout << sc.countVowels("foobar") << endl;
    cout << "pointer to an object " << sc2->countVowels("Foobarfoobar") << endl;

    delete sc2;
    return 0;
}