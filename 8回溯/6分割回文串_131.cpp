/**
 * Middle
 * 
 * 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。

    回文串 是正着读和反着读都一样的字符串。

     

    示例 1：

    输入：s = "aab"
    输出：[["a","a","b"],["aa","b"]]
    示例 2：

    输入：s = "a"
    输出：[["a"]]
     

    提示：

    1 <= s.length <= 16
    s 仅由小写英文字母组成


    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/palindrome-partitioning
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 不要将之理解为分割问题 理解为组合选值更好理解
class Solution {
private:
    vector<vector<string>> result;
    vector<string> path;

public:
    bool isPalindromeSting(string& s, int left, int right) {
        while (left <= right) {
            if (s[left] != s[right]) return false;
            ++left;
            --right;
        }
        return true;
    }

    void backTracking(string& s, int startIndex) {
        if (startIndex == s.size()) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < s.size(); ++i) {
            if (!isPalindromeSting(s, startIndex, i)) continue;
            path.push_back(s.substr(startIndex, i - startIndex + 1));
            backTracking(s, i + 1);
            path.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        backTracking(s, 0);
        return result;
    }
};