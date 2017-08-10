#include <iostream>

using namespace std;

int main(){
    int i = 42;
    int *pi = 0;
    int *pi2 = &i;
    int *pi3;

    pi3 = pi2;
    pi2 = 0;
    
    cout << pi3 << endl;
    cout << pi2 << endl;
    cout << &i << endl;
    cout << *pi3 << endl;

    *pi3 = 32;
    cout << *pi3 << endl;
    cout << i << endl;
    return 0;
}
