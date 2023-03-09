/**
 * Middle
 * 
 * 给你一个字符串 s 和一个字符串列表 wordDict 作为字典。请你判断是否可以利用字典中出现的单词拼接出 s 。

    注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。

     

    示例 1：

    输入: s = "leetcode", wordDict = ["leet", "code"]
    输出: true
    解释: 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。
    示例 2：

    输入: s = "applepenapple", wordDict = ["apple", "pen"]
    输出: true
    解释: 返回 true 因为 "applepenapple" 可以由 "apple" "pen" "apple" 拼接成。
         注意，你可以重复使用字典中的单词。
    示例 3：

    输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
    输出: false
     

    提示：

    1 <= s.length <= 300
    1 <= wordDict.length <= 1000
    1 <= wordDict[i].length <= 20
    s 和 wordDict[i] 仅有小写英文字母组成
    wordDict 中的所有字符串 互不相同


    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/word-break
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

// dp[i]=true 的含义：串长度为i的字符串可以被字典里的单词组成
// 应该先遍历背包 再遍历物品 求排列数 而不是组合数
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordDictSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true; //0只是起一个初始迭代值的作用 背包串从1开始
        for (int i = 1; i <= s.size(); ++i) { //背包串s 下标从0开始
            for (int j = 0; j < i; ++j) {
                string temp = s.substr(j, i - j); //从下标j开始的 i-j 个
                if (wordDictSet.find(temp) != wordDictSet.end() && dp[j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};