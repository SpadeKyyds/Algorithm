/**
 * Easy
 * 
 * 给你一个整数数组 nums 和一个整数 k ，按以下方法修改该数组：

    选择某个下标 i 并将 nums[i] 替换为 -nums[i] 。
    重复这个过程恰好 k 次。可以多次选择同一个下标 i 。

    以这种方式修改数组后，返回数组 可能的最大和 。

     

    示例 1：

    输入：nums = [4,2,3], k = 1
    输出：5
    解释：选择下标 1 ，nums 变为 [4,-2,3] 。
    示例 2：

    输入：nums = [3,-1,0,2], k = 3
    输出：6
    解释：选择下标 (1, 2, 2) ，nums 变为 [3,1,0,2] 。
    示例 3：

    输入：nums = [2,-3,-1,5,-4], k = 2
    输出：13
    解释：选择下标 (1, 4) ，nums 变为 [2,3,-1,5,4] 。

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/maximize-sum-of-array-after-k-negations
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 贪心的思路真的是不固定 要多思考 敢于实践
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0, result = 0;
        // 这里i要添加限定范围 否则会发生数组越界
        for (; i < k && i < nums.size() && nums[i] < 0; ++i) {
            nums[i] = -nums[i];
        }
        sort(nums.begin(), nums.end());
        if ((k - i) % 2 != 0) nums[0] = -nums[0];
        for (int j = 0; j < nums.size(); ++j) {
            result += nums[j];
        }
        return result;
    }
};