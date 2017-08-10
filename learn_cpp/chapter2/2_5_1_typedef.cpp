#include <iostream>
#include "Sales_item.h"

using namespace std;
using SI = Sales_item;

typedef double wages;

int main(){
    wages hourly, weekly;
    SI item;
    //cout << item.isbn() << endl;
    //cout << hourly << weekly << endl;
    
    typedef char* pstring;
    char chara = 'a';
    const pstring cstr = &chara;
    cout << *cstr << endl;
    return 0;

}
