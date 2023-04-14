/**
 * Middle
 * 
 * 给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。如果不存在 公共子序列 ，返回 0 。

    一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。

    例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
    两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。

     

    示例 1：

    输入：text1 = "abcde", text2 = "ace" 
    输出：3  
    解释：最长公共子序列是 "ace" ，它的长度为 3 。
    示例 2：

    输入：text1 = "abc", text2 = "abc"
    输出：3
    解释：最长公共子序列是 "abc" ，它的长度为 3 。
    示例 3：

    输入：text1 = "abc", text2 = "def"
    输出：0
    解释：两个字符串没有公共子序列，返回 0 。
     

    提示：

    1 <= text1.length, text2.length <= 1000
    text1 和 text2 仅由小写英文字符组成。

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/longest-common-subsequence
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 卡尔代码随想录版本
// dp[i][j]: 以 i-1 为结尾的nums1和以 j-1 为结尾的nums2的最长公共子序列的长度
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        for (int i = 1; i <= text1.size(); ++i) {
            for (int j = 1; j <= text2.size(); ++j) {
                if (text1[i - 1] == text2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                // 很妙 后续遇到相似的题 再细细体会
                else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);   //要求不连续 和最长重复子数组的区别体现在这里
            }
        }
        return dp[text1.size()][text2.size()];
    }
};

int main() {
    string text1 = "abcde", text2 = "ace";
    Solution s;
    cout << s.longestCommonSubsequence(text1, text2) << endl;
    return 0;
}