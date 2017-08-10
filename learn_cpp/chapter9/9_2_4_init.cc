#include <vector>
#include <array>
#include <iostream>

int main(){
    std::vector<const char*> articles = {"a", "an", "the"};
/*     std::array<int, 10> ia1; */
    std::array<int, 10> ia3 = {42};
/*     while(ia3.begin() != ia3.end()){ */
        // std::cout << *ia3.begin() << std::endl;
    /* } */
    for (auto i:ia3){
        std::cout << i << std::endl;
    }

    int digs[10] = {0,1,2,3,4,5,6,7,8,9};
    for (auto i:digs){
        std::cout << i << std::endl;
    }
    int cpy[10];
    for (auto i:cpy){
        std::cout << i << std::endl;
    }
    return 0;
}
