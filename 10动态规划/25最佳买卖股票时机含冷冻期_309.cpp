/**
 * Middle
 * 
 * 给定一个整数数组prices，其中第  prices[i] 表示第 i 天的股票价格 。​

    设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

    卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
    注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

     

    示例 1:

    输入: prices = [1,2,3,0,2]
    输出: 3 
    解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]
    示例 2:

    输入: prices = [1]
    输出: 0
     

    提示：

    1 <= prices.length <= 5000
    0 <= prices[i] <= 1000

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
using namespace std;

// dp[i]:第i天结束后的累计最大收益
// dp[i][0]:第i天结束后手上持有股票的累计最大收益
// dp[i][1]:第i天结束后手上没有股票 且处于冷冻期的累计最大收益
// dp[i][2]:第i天结束后手上没有股票 且不处于冷冻期的累计最大收益
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(3));
        dp[0][0] = -prices[0], dp[0][1] = 0, dp[0][2] = 0; //dp[0][1] = 0 理解为当天买入又卖出
        for (int i = 1; i < prices.size(); ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
            dp[i][1] = dp[i - 1][0] + prices[i];
            dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]);
        }
        return max(dp[prices.size() - 1][1], dp[prices.size() - 1][2]);
    }
};

// 空间优化版本：
// 因为i天的状态仅与i-1天相关 因此可以将i-1天的状态存于一个变量 每一次实时更新即可
// dp[i - 1][0]:f0
// dp[i - 1][1]:f1
// dp[i - 1][2]:f2
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int f0 = -prices[0], f1 = 0, f2 = 0;
        for (int i = 1; i < prices.size(); ++i) {
            int f0_temp = max(f0, f2 - prices[i]);
            int f1_temp = f0 + prices[i];
            int f2_temp = max(f1, f2);
            f0 = f0_temp;
            f1 = f1_temp;
            f2 = f2_temp;
        }
        return max(f1, f2);
    }
};