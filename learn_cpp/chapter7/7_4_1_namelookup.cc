#include <iostream>

typedef double Money;
std::string bal;
class Account{
    public:
        Money balance() {return bal;}
    private:
        Money bal;
};

int height;
class Screen {
    public:
        typedef std::string::size_type pos;
        void dummy_fcn(pos height) {
            cursor = width * height;
        }
    private:
        pos cursor = 0;
        pos height = 0, width = 0;
};

int main(){
    Screen test1;
    test1.dummy_fcn(1);

    return 0;
}
