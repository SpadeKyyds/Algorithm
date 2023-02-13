/**
 * Easy
 * 
 * 给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。一旦你支付此费用，即可选择向上爬一个或者两个台阶。

    你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。

    请你计算并返回达到楼梯顶部的最低花费。

     

    示例 1：

    输入：cost = [10,15,20]
    输出：15
    解释：你将从下标为 1 的台阶开始。
    - 支付 15 ，向上爬两个台阶，到达楼梯顶部。
    总花费为 15 。
    示例 2：

    输入：cost = [1,100,1,1,1,100,1,1,100,1]
    输出：6
    解释：你将从下标为 0 的台阶开始。
    - 支付 1 ，向上爬两个台阶，到达下标为 2 的台阶。
    - 支付 1 ，向上爬两个台阶，到达下标为 4 的台阶。
    - 支付 1 ，向上爬两个台阶，到达下标为 6 的台阶。
    - 支付 1 ，向上爬一个台阶，到达下标为 7 的台阶。
    - 支付 1 ，向上爬两个台阶，到达下标为 9 的台阶。
    - 支付 1 ，向上爬一个台阶，到达楼梯顶部。
    总花费为 6 。
     

    提示：

    2 <= cost.length <= 1000
    0 <= cost[i] <= 999

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/min-cost-climbing-stairs
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 时间复杂度O(n) 空间复杂度O(n) 空间复杂度可进一步优化为O(1)
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() + 1);
        // dp[i]表示到达i位置所需最小花费
        dp[0] = 0, dp[1] = 0;
        for (int i = 2; i < cost.size() + 1; ++i) {
            // 这里其实应该逆向思考
            // 为了到达i位置 我只能从i-1位置跳一步或者i-2位置跳两步
            // 那么最小的花费就是 min(i-1位置的dp值加上i-1位置跳跃需要的花费,i-2位置的dp值加上i-2位置跳跃需要的花费)
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[cost.size()]; //顶层为cost.size() 在dp数组里对应的就是dp[cost.size()]
    }
};