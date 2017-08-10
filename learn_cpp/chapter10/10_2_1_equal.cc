#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    vector<int> a({1, 2, 3});
    vector<int> b({1, 2, 3});
    bool value = equal(a.cbegin(), a.cend(), b.cbegin());
    cout << value << endl;

    vector<int> vec;
    auto it = back_inserter(vec);
    *it = 42;
    cout << vec.size() << endl;

    *it = 41;
    cout << vec.size() << endl;

    return 0;
}
