/**
 * Middle
 * 
 * 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

     

    示例 1：

    输入：nums = [1,1,2]
    输出：
    [[1,1,2],
    [1,2,1],
    [2,1,1]]
    示例 2：

    输入：nums = [1,2,3]
    输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
     

    提示：

    1 <= nums.length <= 8
    -10 <= nums[i] <= 10

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/permutations-ii
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
            // 这里第二个条件是树层去重
            if (uesd[i] || (i > 0 && nums[i] == nums[i - 1] && uesd[i - 1] == false)) continue;
            uesd[i] = true;
            path.push_back(nums[i]);
            backTracking(nums, uesd);
            uesd[i] = false;
            path.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backTracking(nums, used);
        return result;
    }
};