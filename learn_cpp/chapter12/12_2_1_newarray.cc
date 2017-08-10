#include <iostream>
#include <string>
#include <memory>

using namespace std;

typedef int arrT[42];

int *pia = new int[42];
int *p = new arrT;

int main(){
    unique_ptr<int []> up(new int[10]);
    for (size_t i = 0; i != 10; ++i)
        up[i] = i;

    shared_ptr<int> sp(new int[10], [](int *p){delete[] p;});
    sp.reset();
    for (size_t i = 0; i != 10; ++i)
        *(sp.get() + i) = i;
    return 0;
}
