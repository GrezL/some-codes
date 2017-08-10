#include <iostream>

using namespace std;

int main(){
    int i = 42;
    int *pi = &i;
    cout << *pi << endl;
    cout << pi << endl;
    *pi = *pi * *pi;
    cout << *pi << endl;
    cout << pi << endl;

    int *test = &i;
    if (test){
        cout << "get ptr" << endl;
    }
    if (*test){
        cout << "get val" << endl;
    }

    int ival = 1024;
    int *pival= &ival;
    int **ppival = &pival;
    cout << pival << endl;
    cout << *pival << endl;
    cout << ppival << endl;
    cout << *ppival << endl;
    cout << **ppival << endl;

    cout << "========section 2========" << endl;
    int a = 42;
    int *pa;
    int *&r = pa;

    r = &a;
    cout << r << endl;
    cout << pa << endl;
    return 0;
}
