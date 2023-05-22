/**
 * Middle
 * 
 * 给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。

    返回 你可以获得的最大乘积 。

     

    示例 1:

    输入: n = 2
    输出: 1
    解释: 2 = 1 + 1, 1 × 1 = 1。
    示例 2:

    输入: n = 10
    输出: 36
    解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
     

    提示:

    2 <= n <= 58

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/integer-break
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        // dp[i] 数组含义: 数字i拆成的数 相乘得到的最大乘积
        vector<int> dp(n + 1);
        for (int i = 2; i < n + 1; ++i) {
            int curMax = 1; //这里相当于是对dp[2]的初始化 如果i=2 则不会进入子循环
            // 这里j < i -1 而不取 j < i 即只乘到2 乘到1无意义 题目中2 <= n <= 58
            for (int j = 1; j < i - 1; ++j) { //这里也可以小优化一下为：j <= i/2
                // 这里最难的其实是需要取 max(j * (i - j), j * dp[i - j])
                // 我只想到了j * dp[i - j] 并未想到j * (i - j)
                // i-j不再拆分和i-j继续拆分
                curMax = max(curMax, max(j * (i - j), j * dp[i - j]));
            }
            dp[i] = curMax;
        }
        return dp[n];
    }
};