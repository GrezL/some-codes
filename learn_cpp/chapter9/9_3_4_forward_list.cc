#include <forward_list>
#include <iostream>

int main(){
    std::forward_list<int> flst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto prev = flst.before_begin();
    auto curr = flst.begin();
/*     std::cout << *prev << *curr << std::endl; */
    while(curr != flst.end()){
        if (*curr % 2)
            curr = flst.erase_after(prev);
        else {
            prev = curr;
            ++curr;
        }
    }
    for(auto iter = flst.begin(); iter != flst.end(); ++iter){
        std::cout << *iter << std::endl;
    }
    return 0;
}