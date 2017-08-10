#include <iostream>
#include <array>
#include <list>
#include <string>
#include <vector>

int main(){
    std::array<int, 10> arr1({1, 2, 3, 4, 5, 6, 7, 8, 9, 0}); 
    std::array<int, 10> arr2({1});
    swap(arr1, arr2);
    for (auto i:arr1){
        std::cout << i << ' ';
    }
    std::cout << std::endl;
    for (auto i:arr2){
        std::cout << i << ' ';
    }
    std::cout << std::endl; 
    std::list<std::string> names;
    std::vector<const char*> oldstyle;
    names.assign(oldstyle.cbegin(), oldstyle.cend());

    std::vector<int> c;
    std::cout << c.at(0) << std::endl;


    return 0;
}
