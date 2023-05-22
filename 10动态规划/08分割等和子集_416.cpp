/**
 * Middle
 * 
 * 给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

     

    示例 1：

    输入：nums = [1,5,11,5]
    输出：true
    解释：数组可以分割成 [1, 5, 5] 和 [11] 。
    示例 2：

    输入：nums = [1,2,3,5]
    输出：false
    解释：数组不能分割成两个元素和相等的子集。
     

    提示：

    1 <= nums.length <= 200
    1 <= nums[i] <= 100

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/partition-equal-subset-sum
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
using namespace std;

// dp[j]含义：重量为j的背包可以装的物品的最大价值
// 本题物品的重量和价值都是nums[i] 这一点要理解透彻
// 时间复杂度O(n^2) 空间复杂度O(n)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = 0;
        for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); ++iter) {
            target += *iter;
        }
        if (target % 2 != 0) return false;
        target /= 2;
        vector<int> dp(target + 1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = target; j >= nums[i]; --j) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
                // 这里正好装满的判定也可以放在循环外
                // 因为dp[j]取的都是最大值 如果有一个元素的值是大于target
                // 那么这肯定是false 因为这个值不可能小下来
                if (dp[target] > target) return false;
                if (dp[target] == target) return true;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums{1, 5, 11, 5};
    cout << s.canPartition(nums) << endl;
    return 0;
}