/**
 * Middle
 * 
 * 给你一个整数数组 coins 表示不同面额的硬币，另给一个整数 amount 表示总金额。

    请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回 0 。

    假设每一种面额的硬币有无限个。 

    题目数据保证结果符合 32 位带符号整数。

     

    示例 1：

    输入：amount = 5, coins = [1, 2, 5]
    输出：4
    解释：有四种方式可以凑成总金额：
    5=5
    5=2+2+1
    5=2+1+1+1
    5=1+1+1+1+1
    示例 2：

    输入：amount = 3, coins = [2]
    输出：0
    解释：只用面额 2 的硬币不能凑成总金额 3 。
    示例 3：

    输入：amount = 10, coins = [10] 
    输出：1
     

    提示：

    1 <= coins.length <= 300
    1 <= coins[i] <= 5000
    coins 中的所有值 互不相同
    0 <= amount <= 5000


    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/coin-change-ii
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
using namespace std;

// dp[j]:可以凑成总金额为j的方案数
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // if (coins.size() == 1 && amount % coins[0] != 0) return 0; 这里不加也行 为什么？
        // 这题还有交换两层for循环的顺序 一个是排列数 一个是组合数 需要理解
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < coins.size(); ++i) {
            for (int j = coins[i]; j <= amount; ++j) {
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};