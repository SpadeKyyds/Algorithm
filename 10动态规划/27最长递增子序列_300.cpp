/**
 * Middle
 * 
 * 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

    子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。

     
    示例 1：

    输入：nums = [10,9,2,5,3,7,101,18]
    输出：4
    解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
    示例 2：

    输入：nums = [0,1,0,3,2,3]
    输出：4
    示例 3：

    输入：nums = [7,7,7,7,7,7,7]
    输出：1
     

    提示：

    1 <= nums.length <= 2500
    -104 <= nums[i] <= 104
     

    进阶：

    你能将算法的时间复杂度降低到 O(n log(n)) 吗?

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/longest-increasing-subsequence
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 这是错误的 无法跳过暂时的最大值 而去选择更小的相对更长的子序列
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int length = 0;
//         for (int i = 0; i < nums.size() - 1; ++i) {
//             vector<int> LIS;
//             LIS.push_back(nums[i]);
//             for (int j = i + 1; j < nums.size(); ++j) {
//                 if (nums[j] > *(LIS.end() - 1)) LIS.push_back(nums[j]);
//             }
//             if(LIS.size() > length) length = LIS.size();
//         }
//         return length;
//     }
// };

// 动态规划解法
// 时间复杂度O(n^2) 空间复杂度O(n)
// dp[i]:以nums[i]为结尾的数组中 最长严格递增子序列的长度
// 注意这里最后取最大值的时候 并不是dp数组的最后一个值 应该是dp数组中的最大值
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};