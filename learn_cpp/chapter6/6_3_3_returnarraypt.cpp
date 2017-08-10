#include <iostream>

using namespace std;

int odd[] = {1, 3, 4, 7, 9};
int even[] = {0, 2, 4, 6, 8};

decltype(odd) *arrPtr(int i){
    return (i % 2) ? &odd : &even;
}

int main(){
    cout << &odd[0] << endl;
    cout << &even[0] << endl;
    cout << arrPtr(1) << endl;
    cout << arrPtr(2) << endl; 
    return 0;
}
