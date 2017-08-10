#include <iostream>
#include <vector>
#include <memory>

using namespace std;

shared_ptr<int> clone(int p){
    return shared_ptr<int>(new int(p));
}

int main(){
    int *pi = new int(1024);
    cout << *pi << endl;
    vector<int> *pv = new vector<int> {0,1,2,3,4,5,6,7,8,9}; 
    for (auto i: *pv)
        cout << i << endl;

    auto a(clone(3));
    auto b = a;
    cout << *a << endl;
    if (a.unique()){
        cout << "it's unique!" << endl;
    }

    return 0;
}
