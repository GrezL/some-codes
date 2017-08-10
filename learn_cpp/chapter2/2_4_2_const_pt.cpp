#include <iostream>

using namespace std;

int main(){
    int errNumb = 0;
    int *const curErr = &errNumb;
    const double pi = 3.14159;
    const double *const pip = &pi;

    *curErr = 1;
    cout << errNumb << endl;
    return 0;
}
