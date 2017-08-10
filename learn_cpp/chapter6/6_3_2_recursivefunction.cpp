#include <iostream>
#include <vector>

using namespace std;

int factorial(int val){
    if (val > 1)
        return factorial(val - 1) * val;
    return 1;
}

void print(vector<int> ivec, vector<int>::size_type j){
    if (j != ivec.size() - 1)
        print(ivec, j + 1);
    cout << ivec[j] << endl;
}

char &get_val(string &str, string::size_type ix){
    return str[ix];
}

string actual("actual");
string expected("expected");

vector<string> process(){
    if(actual.empty())
        return {};
    else if (expected == actual)
        return {"functionX", "ok"};
    else
        return {"functionX", actual, expected};
}


int main(){
    cout << factorial(5) << endl;
    string s("hello");
    get_val(s, 0) = 'A';
    cout << s << endl;
    process();
    return 0;

}

