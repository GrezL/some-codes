#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        int titleToNumber(string s){
            int result = 0;
            for(auto k:s){
                result = result*26 + k-64;
            }
            return result;
        }
};

int main(){
    string s = "AA";
    cout << Solution().titleToNumber(s) << endl;
    return 0;
}
