#include <iostream>
#include <string>

using namespace std;

int sum(int a, int b){
    return a + b;
}

int sum(int a, int b, int c){
    return a + b + c;
}

string sum(string a, string b){
    return a + b;
}

int main(){
    cout << sum(1,2) << endl;
    cout << sum(1,2,3) << endl;
    cout << sum("hello ", "world");
    return 0;
}
