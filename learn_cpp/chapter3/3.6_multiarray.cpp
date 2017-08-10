#include <iostream>

using namespace std;

int main(){
    int ia[3][4];
    for (auto p = ia; p != ia + 3; ++p){
        for (auto q = *p; q != *p + 4; ++q){
            cout << *q << ' ';
        }
        cout << endl;
    }


    for (auto p = begin(ia); p != end(ia); ++p){
        for (auto q = begin(*p); q != end(*p); ++q){
            cout << *q << ' ';
        }
        cout << endl;
    }   
}
