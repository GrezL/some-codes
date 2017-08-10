#include <iostream>

using namespace std;

int main(){
    const int ci = 0, &cj = ci;
    decltype(ci) x = 0;
    decltype(cj) y = x;
    
    cout << x << endl;
    cout << y << endl;

    int i =42, *p = &i, &r = i;
    decltype(r + 0) b;
    cout << b << endl;
    int32_t a;
    cout << a << endl;
    cout << *p << endl;
}
