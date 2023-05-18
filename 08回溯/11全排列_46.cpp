/**
 * Middle
 * 
 * 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

     

    示例 1：

    输入：nums = [1,2,3]
    输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
    示例 2：

    输入：nums = [0,1]
    输出：[[0,1],[1,0]]
    示例 3：

    输入：nums = [1]
    输出：[[1]]
     

    提示：

    1 <= nums.length <= 6
    -10 <= nums[i] <= 10
    nums 中的所有整数 互不相同

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/permutations
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;

public:
    void backTracking(vector<int>& nums, vector<bool>& uesd) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (uesd[i]) continue;
            uesd[i] = true;
            path.push_back(nums[i]);
            backTracking(nums, uesd);
            uesd[i] = false;
            path.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        backTracking(nums, used);
        return result;
    }
};