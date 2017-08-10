#include <iostream>
#include <string>

using namespace std;

bool lengthCompare(const string &a, const string &b){
    return a > b;
};

bool (*pf)(const string &, const string &);

int main(){
    pf = lengthCompare;
    return 0;
}
