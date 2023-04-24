/**
 * Middle
 * 
 * 给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。

    回文字符串 是正着读和倒过来读一样的字符串。

    子字符串 是字符串中的由连续字符组成的一个序列。

    具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。

     

    示例 1：

    输入：s = "abc"
    输出：3
    解释：三个回文子串: "a", "b", "c"
    示例 2：

    输入：s = "aaa"
    输出：6
    解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
     

    提示：

    1 <= s.length <= 1000
    s 由小写英文字母组成

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/palindromic-substrings
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// dp[i][j]:s[i, j]是否为回文串
class Solution {
public:
    int countSubstrings(string s) {
        int result = 0;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        for (int i = s.size() - 1; i >= 0; --i) {
            for (int j = i; j < s.size(); ++j) {
                if (s[i] == s[j]) {
                    if (j - i <= 1 || dp[i + 1][j - 1]) {
                        dp[i][j] = true;
                        ++result;
                    }
                }
            }
        }
        return result;
    }
};