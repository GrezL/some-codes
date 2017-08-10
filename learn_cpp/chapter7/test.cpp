#include <iostream>
#include <string>

using namespace std;

int main(){
    string str = "testastring";
    for (auto i=0; i<=str.length(); ++i)
        cout << str[i] << endl;
};
