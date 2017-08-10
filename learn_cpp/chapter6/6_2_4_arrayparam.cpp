#include <iostream>

using namespace std;

void print(const int *beg, const int *end){
    while (beg != end)
        cout << *beg++ << endl;
}

void print(const int ia[], size_t size){
    for (size_t i = 0; i != size; ++i)
        cout << ia[i] << endl;
}

void print(const char *cp){
    if (cp)
        while (*cp)
            cout << *cp++ << endl;
}

void print(int (&arr)[4]){
    for (auto item: arr)
        cout << item << endl;
}

int main(){
    int j[2] = {0, 1};
    print(begin(j), end(j));

    int k[] = {0, 1, 2, 3};
    print(k, end(k) - begin(k));
    //
    const string test = "teststring";
    const char *cp = test.c_str();
    cout << *cp << endl;
    ++cp;
    cout << *cp << endl;
    
    print(k);
}
