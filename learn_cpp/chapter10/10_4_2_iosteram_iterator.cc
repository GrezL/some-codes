#include <iostream>
#include <iterator>
#include <vector>
#include "Sales_item.h"

using namespace std;

ostream &print(int i, char c){
    return cout << i << c;
}

int main(){
//    istream_iterator<int> in_iter(cin), eof;
//    vector<int> vec(in_iter, eof);
//    while(in_iter != eof)
//       vec.push_back(*in_iter++);
//    ostream_iterator<int> out_iter(cout, ">");
//    copy(vec.begin(), vec.end(), out_iter);
//    cout << endl;


    istream_iterator<Sales_item> item_iter(cin), eof;
    ostream_iterator<Sales_item> out_iter(cout, "\n");

    Sales_item sum = *item_iter++;
    while(item_iter != eof){
        if (item_iter->isbn() == sum.isbn())
            sum += *item_iter++;
        else {
            out_iter = sum;
            sum = *item_iter++;
        }
    }
    out_iter = sum;
    return 0;
}
