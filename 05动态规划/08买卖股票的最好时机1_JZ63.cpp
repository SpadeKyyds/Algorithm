#include <iostream>
#include <vector>
using namespace std;

// 贪心解法 时间复杂度O(n) 空间复杂度O(1)
class Solution {
public:
    // 即遍历一圈找出最小的花费和最大的利益值
    int maxProfit(vector<int>& prices) {
        int benefit = 0, cost = INT16_MAX;
        for (int ele : prices) {
            cost = min(ele, cost);
            benefit = max(benefit, ele - cost);
        }
        return benefit;
    }
};

// 动态规划解法 时间复杂度O(n) 空间复杂度O(n)
// dp[i][0]:第i+1天持有股票所能获得的最大收益
// dp[i][1]:第i+1天不持有股票所能获得的最大收益
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < prices.size(); ++i) {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][0] + prices[i], dp[i - 1][1]);
        }
        return dp[prices.size() - 1][1];
    }
};