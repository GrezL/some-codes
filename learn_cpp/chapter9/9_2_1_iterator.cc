#include <list>
#include <iostream>

int main(){
    std::list<int> lst1;
    std::list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.end();
    while (iter1 != iter2){
        std::cout << *iter1 << std::endl;
        ++iter1;
    }
/*     std::cout << lst1.size() << std::endl; */
    return 0;
}
