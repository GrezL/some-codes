#include <iostream>

using namespace std;

int main(){
    double dval = 42.00;
    double *pd = &dval;
    double *pd2 = pd;
    cout << *pd << endl;
    cout << *pd2 << endl;
    cout << &dval << endl;
    cout << pd << endl;
    return 0;
}
