#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int int_arr[] = {0, 1, 2, 3, 4, 5};
    vector<int> ivec(begin(int_arr), end(int_arr));
    for (auto iter = ivec.begin(); iter != ivec.end(); ++iter)
       cout << *iter << endl; 
}
