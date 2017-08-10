#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string s("some string");
    for (auto it = s.begin(); it != s.end(); ++it){
        cout << *it;
    }
    cout << endl;
    
    vector<string> c;
    for (auto iter = c.cbegin(); iter != c.cend() && !iter->empty(); ++iter)
        cout << *iter << endl;
    return 0;
}
