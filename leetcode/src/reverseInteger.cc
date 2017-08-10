#include <iostream>

using namespace std;

class Solution{
    public:
        int revers(int x){
            long long res = 0;
            while (x != 0){
                res = 10 * res + x % 10;
                x = x/10;
            }
            return (res > INT_MAX || res < INT_MIN) ? 0: res;
        }
};
