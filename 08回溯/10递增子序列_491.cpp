/**
 * Middle
 * 
 * 给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中 至少有两个元素 。你可以按 任意顺序 返回答案。

    数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。

     

    示例 1：

    输入：nums = [4,6,7,7]
    输出：[[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
    示例 2：

    输入：nums = [4,4,3,2,1]
    输出：[[4,4]]
     

    提示：

    1 <= nums.length <= 15
    -100 <= nums[i] <= 100

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/non-decreasing-subsequences
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

// 这题很难 可以说是hard题了
// 树层去重如果不能排序 考虑用哈希存储来做
// 这题的树枝要进行一定剪枝 可以用vector的back来做比较 进行判断
class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;

public:
    void backTracking(vector<int>& nums, int startIndex) {
        unordered_set<int> un_set;
        if (path.size() > 1) result.push_back(path);
        for (int i = startIndex; i < nums.size(); ++i) {
            // 去重操作一般在此处 continue
            if ((!path.empty() && nums[i] < path.back()) || un_set.find(nums[i]) != un_set.end()) {
                continue;
            }
            un_set.insert(nums[i]);
            path.push_back(nums[i]);
            backTracking(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backTracking(nums, 0);
        return result;
    }
};