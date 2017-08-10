#include <iostream>
#include <string>

int main(){
    long long k;
    std::cin >> k;
    if(k % 2 == 0){
        std::cout << k/2 << std::endl;
        for(auto i=0; i != k/2; ++i){
            std::cout << "2 ";
        }
    }else{
        std::cout << k/2 << std::endl;
        for(auto i=0; i != k/2 - 1; ++i){
            std::cout << "2 ";
        }
        std::cout << "3" << std::endl;
    }
    return 0;
}
