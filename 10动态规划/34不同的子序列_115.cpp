/**
 * Hard
 * 
 * 给你两个字符串 s 和 t ，统计并返回在 s 的 子序列 中 t 出现的个数。

    题目数据保证答案符合 32 位带符号整数范围。

     

    示例 1：

    输入：s = "rabbbit", t = "rabbit"
    输出：3
    解释：
    如下所示, 有 3 种可以从 s 中得到 "rabbit" 的方案。
    rabbbit
    rabbbit
    rabbbit
    示例 2：

    输入：s = "babgbag", t = "bag"
    输出：5
    解释：
    如下所示, 有 5 种可以从 s 中得到 "bag" 的方案。 
    babgbag
    babgbag
    babgbag
    babgbag
    babgbag
     

    提示：

    1 <= s.length, t.length <= 1000
    s 和 t 由英文字母组成

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/distinct-subsequences
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    // dp[i][j]:以i-1为结尾的s中有以j-1为结尾的t的个数
    int numDistinct(string s, string t) {
        vector<vector<unsigned long long>> dp(s.size() + 1, vector<unsigned long long>(t.size() + 1, 0));
        for (int i = 0; i <= s.size(); ++i) dp[i][0] = 1;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 1; j <= t.size(); ++j) {
                if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[s.size()][t.size()];
    }
};