#include <iostream>
#include "Sales_item.h"

using namespace std;

int main(){
    Sales_item item1, item2;
    if (cin >> item1 >> item2){
        if (item1.isbn() == item2.isbn()){
            cout << item1 + item2 << endl;
            return 0;
        }else{
            cout << "Data must refer to same ISBN" << endl;
            return -1;
        }
    }
}
