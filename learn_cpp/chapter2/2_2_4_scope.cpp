#include <iostream>

using namespace std;

int reused= 42;

int main(){
    cout << reused << endl;
    int reused = 0;
    cout << reused << endl;
    cout << ::reused << endl;
    return 0;
}
