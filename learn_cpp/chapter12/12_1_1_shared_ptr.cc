#include <memory>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main(){
    shared_ptr<string> p1;
    if (p1 && p1->empty())
        *p1 = "hi";

    shared_ptr<string> p3 = make_shared<string>(10, '9');
    cout << *p3 << endl; 

    auto p6 = make_shared<vector<string>>();

    auto p = make_shared<int>(42);
    auto q(p);
    cout << *q << endl;
    return 0;
}
