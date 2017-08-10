#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int re_int = 0;
        int d_v = x;
        while(x != 0){
            re_int = x % 10 + 10 * re_int;
            x = x / 10;
        };
        re_int = (re_int > INT_MAX || re_int < 0) ? 0: re_int;
        if (re_int != d_v){
            return false;
        }
        else{
            return true;
        }
    }
};
