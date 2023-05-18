/**
 * 难度：中等
 * 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请

    你返回所有和为 0 且不重复的三元组。

    注意：答案中不可以包含重复的三元组。

     

     

    示例 1：

    输入：nums = [-1,0,1,2,-1,-4]
    输出：[[-1,-1,2],[-1,0,1]]
    解释：
    nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
    nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
    nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
    不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
    注意，输出的顺序和三元组的顺序并不重要。
    示例 2：

    输入：nums = [0,1,1]
    输出：[]
    解释：唯一可能的三元组和不为 0 。
    示例 3：

    输入：nums = [0,0,0]
    输出：[[0,0,0]]
    解释：唯一可能的三元组和为 0 。

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/3sum
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        vector<vector<int>> result;
        for (int i = 0; i < len - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; //一级去重
            if (nums[i] > 0 || nums[len - 1] < 0) break; //一级剪枝
            int j = i + 1, k = len - 1;
            while (j < k) {
                // if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                if ((long) nums[i] + nums[j] + nums[k] < 0) ++j;
                else if ((long) nums[i] + nums[j] + nums[k] > 0) --k;
                else {
                    result.push_back({nums[i], nums[j], nums[k]});
                    ++j;
                    --k;
                    // 内部去重
                    while (j < k && nums[j] == nums[j - 1]) ++j;
                    while (j < k && nums[k] == nums[k + 1]) --k;
                }
            }
        }
        return result;
    }
};