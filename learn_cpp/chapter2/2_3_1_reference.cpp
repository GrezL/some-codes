#include <iostream>

using namespace std;

int main(){
    int ival = 1024;
    int &refVal = ival;
    refVal = 2;
    int ii = refVal;
    
    cout << refVal << endl;
    cout << ii << endl;

    int *ptriVal = &ival;
    int *ptrRefVal = &refVal;
    int *ptrii = &ii;
    cout << ptriVal << endl;
    cout << ptrRefVal << endl;
    cout << ptrii << endl;
    return 0;
}
