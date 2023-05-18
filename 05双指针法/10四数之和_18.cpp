/**
 * 难度：中等
 * 给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：

    0 <= a, b, c, d < n
    a、b、c 和 d 互不相同
    nums[a] + nums[b] + nums[c] + nums[d] == target
    你可以按 任意顺序 返回答案 。

     

    示例 1：

    输入：nums = [1,0,-1,0,-2,2], target = 0
    输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
    示例 2：

    输入：nums = [2,2,2,2,2], target = 8
    输出：[[2,2,2,2]]

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/4sum
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 此题关键点在于去重 需要多加注意 还好已经掌握 可以复述出来
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int len = nums.size();
        for (int i = 0; i < len - 3; ++i) {
            // 一级剪枝
            if ((long) nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
            if ((long) nums[i] + nums[len - 1] + nums[len - 2] + nums[len - 3] < target) continue;
            // 一级去重
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < len - 2; ++j) {
                // 二级剪枝
                if ((long) nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
                if ((long) nums[i] + nums[j] + nums[len - 1] + nums[len - 2] < target) continue;
                // 二级去重
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int s = j + 1, t = len - 1;
                while (s < t) {
                    if ((long) nums[i] + nums[j] + nums[s] + nums[t] < target) ++s;
                    else if ((long) nums[i] + nums[j] + nums[s] + nums[t] > target) --t;
                    else {
                        result.push_back({nums[i], nums[j], nums[s], nums[t]});
                        ++s;
                        --t;
                        // 三四级去重
                        while (s < t && nums[s] == nums[s - 1]) ++s;
                        while (s < t && nums[t] == nums[t + 1]) --t;
                    }
                }
            }
        }
        return result;
    }
};