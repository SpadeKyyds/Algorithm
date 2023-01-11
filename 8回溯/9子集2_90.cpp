/**
 * Middle
 * 
 * 给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。

    解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。

     

    示例 1：

    输入：nums = [1,2,2]
    输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
    示例 2：

    输入：nums = [0]
    输出：[[],[0]]
     

    提示：

    1 <= nums.length <= 10
    -10 <= nums[i] <= 10


    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/subsets-ii
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;

public:
    void backTracking(vector<int>& nums, int startIndex) {
        result.push_back(path);
        for (int i = startIndex; i < nums.size(); ++i) {
            if (i > startIndex && nums[i] == nums[i - 1]) continue;
            path.push_back(nums[i]);
            backTracking(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // 要记得排序哟
        sort(nums.begin(), nums.end());
        backTracking(nums, 0);
        return result;
    }
};