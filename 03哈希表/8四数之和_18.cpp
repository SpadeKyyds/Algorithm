#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 这种求多数之和的双指针解法应该彻底掌握
// 时间复杂度O(n^3) 空间复杂度O(logn)或者O(n) 主要来源于对数组的排序操作
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int len = nums.size();
        if (len < 4) return result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len - 3; ++i) {
            // 一级去重
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            // 一级剪枝
            if ((long) nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
            if ((long) nums[i] + nums[len - 1] + nums[len - 2] + nums[len - 3] < target) continue;
            for (int j = i + 1; j < len - 2; ++j) {
                // 二级去重
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                // 二级剪枝
                if ((long) nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
                if ((long) nums[i] + nums[j] + nums[len - 1] + nums[len - 2] < target) continue;
                int left = j + 1, right = len - 1;
                while (left < right) {
                    if ((long) nums[i] + nums[j] + nums[left] + nums[right] > target) --right;
                    else if ((long) nums[i] + nums[j] + nums[left] + nums[right] < target) ++left;
                    else {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        // 三级和四级去重
                        while (left < right && nums[left] == nums[left + 1]) ++left;
                        while (left < right && nums[right] == nums[right - 1]) --right;
                        ++left;
                        --right;
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    vector<vector<int>> res;
    Solution s;
    vector<int> nums = {1000000000, 1000000000, 1000000000, 1000000000};
    s.fourSum(nums, 0);
    return 0;
}