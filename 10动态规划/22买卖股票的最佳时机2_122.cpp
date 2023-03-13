/**
 * Middle
 * 
 * 给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。

    在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。

    返回 你能获得的 最大 利润 。

     

    示例 1：

    输入：prices = [7,1,5,3,6,4]
    输出：7
    解释：在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4 。
         随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6 - 3 = 3 。
        总利润为 4 + 3 = 7 。
    示例 2：

    输入：prices = [1,2,3,4,5]
    输出：4
    解释：在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4 。
         总利润为 4 。
    示例 3：

    输入：prices = [7,6,4,3,1]
    输出：0
    解释：在这种情况下, 交易无法获得正利润，所以不参与交易可以获得最大利润，最大利润为 0 。
     

    提示：

    1 <= prices.length <= 3 * 104
    0 <= prices[i] <= 104


    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
using namespace std;

// 动态规划解法: 时间复杂度O(n) 空间复杂度O(n)
// 定义了一个二维dp数组
// dp[i][0]:第i+1天持有股票所能获得的最大收益
// dp[i][1]:第i+1天不持有股票所能获得的最大收益
// 针对于第i天的状态二义性进行分析 根据前一天的状态来确定
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < prices.size(); ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]); //可多次买入 手上现金为dp[i - 1][1]
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
        return max(dp[prices.size() - 1][0], dp[prices.size() - 1][1]);
    }
};