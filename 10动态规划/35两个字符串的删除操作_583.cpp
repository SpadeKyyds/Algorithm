/**
 * Middle
 * 
 * 给定两个单词 word1 和 word2 ，返回使得 word1 和  word2 相同所需的最小步数。

    每步 可以删除任意一个字符串中的一个字符。

     

    示例 1：

    输入: word1 = "sea", word2 = "eat"
    输出: 2
    解释: 第一步将 "sea" 变为 "ea" ，第二步将 "eat "变为 "ea"
    示例  2:

    输入：word1 = "leetcode", word2 = "etco"
    输出：4
     

    提示：

    1 <= word1.length, word2.length <= 500
    word1 和 word2 只包含小写英文字母

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/delete-operation-for-two-strings
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// dp[i][j]:nums1[i - 1]和nums2[j - 1]中最长公共子序列的长度
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector <vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1));
        for (int i = 1; i <= word1.size(); ++i) {
            for (int j = 1; j <= word2.size(); ++j) {
                if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return word1.size() + word2.size() - 2 * dp[word1.size()][word2.size()];
    }
};

// 版本二
// dp[i][j]:nums1[i - 1]和nums2[j - 1]为达到相同 所需删除的最小步数
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector <vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1));
        for (int j = 0; j < dp[0].size(); ++j) dp[0][j] = j;
        for (int i = 0; i < dp.size(); ++i) dp[i][0] = i;
        for (int i = 1; i <= word1.size(); ++i) {
            for (int j = 1; j <= word2.size(); ++j) {
                if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
            }
        }
        return dp[word1.size()][word2.size()];
    }
};