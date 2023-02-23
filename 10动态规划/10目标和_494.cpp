/**
 * Middle
 * 
 * 给你一个整数数组 nums 和一个整数 target 。

    向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：

    例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
    返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。

     

    示例 1：

    输入：nums = [1,1,1,1,1], target = 3
    输出：5
    解释：一共有 5 种方法让最终目标和为 3 。
    -1 + 1 + 1 + 1 + 1 = 3
    +1 - 1 + 1 + 1 + 1 = 3
    +1 + 1 - 1 + 1 + 1 = 3
    +1 + 1 + 1 - 1 + 1 = 3
    +1 + 1 + 1 + 1 - 1 = 3
    示例 2：

    输入：nums = [1], target = 1
    输出：1
     

    提示：

    1 <= nums.length <= 20
    0 <= nums[i] <= 1000
    0 <= sum(nums[i]) <= 1000
    -1000 <= target <= 1000


    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/target-sum
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
using namespace std;

// 回溯 暴力解法 
// 时间复杂度O(2^n) n为nums数组的长度 每一个元素都有两种取法 即枚举每一个元素的取值
// 空间复杂度O(n) 取决于递归调用的栈空间
class Solution {
public:
    int result = 0;
    void backTracking(vector<int>& nums, int target, int start) {
        if (start == nums.size()) {
            if (target == 0) ++result;
        }
        else {
            backTracking(nums, target - nums[start], start + 1);
            backTracking(nums, target + nums[start], start + 1);
        }
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        backTracking(nums, target, 0);
        return result;
    }
};

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); ++iter) {
            sum += *iter;
        }
        if (sum - target < 0 || (sum - target) % 2 != 0) return 0;
        int capacity = (sum - target) / 2;
        vector<int> dp(capacity + 1);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = capacity; j >= nums[i]; --j) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[capacity];
    }
};