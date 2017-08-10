#include <iterator>
#include <algorithm>
#include <list>
#include <iostream>

using namespace std;

ostream &print(int i, char c){
    return cout << i << c;
}

int main(){
    list<int> lst = {1, 2, 3, 4};
    list<int> lst1, lst2;
    copy(lst.begin(), lst.end(), front_inserter(lst1));
    for_each(lst1.begin(), lst1.end(), bind(print, std::placeholders::_1, ' '));
    cout << endl;

    copy(lst.begin(), lst.end(), back_inserter(lst2));
    for_each(lst2.begin(), lst2.end(), bind(print, std::placeholders::_1, ' '));
    cout << endl;
    return 0;
}
