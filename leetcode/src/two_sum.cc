#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for (auto it = 0; it != nums.size(); ++it){
            int the_other = target - nums[it];
            for(auto othit = it + 1; othit != nums.size(); ++othit){
                if (nums[othit] == the_other){
                    result.push_back(it);
                    result.push_back(othit);
                    break;
                }
            }
        }
        return result;
    }
};
