#include <iostream>

using namespace std;

int main(){
    int i = 42;
    int *r = &i;
    //cout << r << endl;
    *r = 41;
    //cout << &i << endl;
    //cout << r << endl;
    //cout << i << endl;
    //cout << *r << endl;

    double dval = 3.14;
    const double *ptdval = &dval;
    cout << ptdval << endl;
    cout << *ptdval << endl;
    return 0;
}
