#include <iostream>
#include <string>

using namespace std;

int main(){
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *e = &arr[10];
    for (int *b = arr; b != e; ++b)
        cout << *b << endl;

    int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *beg = begin(ia);
    int *last = end(ia);
    cout << *beg << endl;
    cout << *last << endl;
    return 0;
}
