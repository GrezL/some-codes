#include <iostream>

using namespace std;

int decl(){
    int i = 42;
    return i;
}

extern double pi = 3.14;

int main(){
    cout << pi << endl;
    cout << decl() << endl;
}
