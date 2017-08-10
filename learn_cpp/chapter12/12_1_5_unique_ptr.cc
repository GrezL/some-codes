#include <memory>
#include <iostream>

using namespace std;

unique_ptr<int> clone(int p){
    return unique_ptr<int>(new int(p));
}

int main(){
    unique_ptr<string> p1(new string("Stegosaurus"));
    unique_ptr<string> p2(p1.release()); 
    cout << *p2 << endl;
    unique_ptr<string> p3 (new string("Trex"));
    p2.reset(p3.release());
    cout << *p2 << endl;
    return 0;
}
