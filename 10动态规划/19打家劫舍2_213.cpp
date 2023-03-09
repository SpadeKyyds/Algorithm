#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int linearRob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); ++i) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[nums.size() - 1];
    }

    // 这种直接复用之前的代码逻辑 函数封装 需要学习 
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector<int> robFirst(nums.begin(), nums.end() - 1);
        vector<int> robLast(nums.begin() + 1, nums.end());
        return max(linearRob(robFirst), linearRob(robLast));
    }

};