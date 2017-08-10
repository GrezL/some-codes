#include <string>
#include <iostream>

int main(){
    std::string s("hello world!");
    s.insert(s.end(), 5, '!');
    std::cout << s << std::endl;
    return 0;
}
