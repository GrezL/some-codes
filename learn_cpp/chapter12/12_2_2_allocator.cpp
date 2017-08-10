#include <memory>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    allocator<string> alloc;
    auto const p = alloc.allocate(3);
    auto q = p;
    alloc.construct(q++);
    alloc.construct(q++, 10, 'c');
    cout << *p << endl;

    while (q != p)
        alloc.destroy(--q);

    alloc.deallocate(p, 3);

    vector<int> vi{1, 2, 3, 4, 5};
    allocator<int> alloc_int;
    auto pi = alloc_int.allocate(vi.size() * 2);
    auto qi = uninitialized_copy(vi.begin(), vi.end(), pi);
    uninitialized_fill_n(qi, vi.size(), 42);
    
    return 0;
}
