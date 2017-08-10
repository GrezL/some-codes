#include <string>
#include <iostream>

struct Data {
    int ival;
    std::string s;
};

int main(){
    Data val1 = {0, "Anna"};
    std::cout << val1.ival << '\n' <<  val1.s << std::endl;
    return 0;
}


