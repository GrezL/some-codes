#include <iostream>

struct X {
    friend void f(){};
    void g();
    void h();
};

void f();
foid X::h() {return f();}
