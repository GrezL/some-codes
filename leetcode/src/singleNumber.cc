#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int singleNumber(vector<int>& nums){
            int result = 0;
            for(auto k: nums)
                result ^= k;
            return result;
        }
};

int main(){
    vector<int> v{2, 2, 1};
    int result = Solution().singleNumber(v);
    cout << result << endl;
    return 0;
}
