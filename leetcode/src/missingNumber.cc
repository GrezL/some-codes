#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int missingNumber(vector<int>& nums){
            int result = 0;
            for (int n = 0; n != int(nums.size()); ++n)
                result ^= nums[n] ^ (n + 1);
            return result;
        }
};

int main(){
    vector<int> v{1, 0};
    int result = Solution().missingNumber(v);
    cout << result << endl;
    return 0;
}
