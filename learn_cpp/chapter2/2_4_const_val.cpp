#include <iostream>
#include "2_4_const_val.h"

using namespace std;

int main(){
    extern const int shareVal;
    cout << shareVal << endl;
    return 0;
}
