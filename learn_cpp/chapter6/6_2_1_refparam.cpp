#include <iostream>

using namespace std;

void reset(int *ip){
    ip = 0;
}

void reset1(int &ip){
    ip = 0;
}

int main(){
    int a = 42;
    reset(&a);
    cout << "value a is: " << a << endl;

    reset1(a);
    cout << "value a is: " << a << endl;
}
