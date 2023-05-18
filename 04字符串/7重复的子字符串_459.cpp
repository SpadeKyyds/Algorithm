/**
 * 难度：简单
 * 给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。

     

    示例 1:

    输入: s = "abab"
    输出: true
    解释: 可由子串 "ab" 重复两次构成。
    示例 2:

    输入: s = "aba"
    输出: false
    示例 3:

    输入: s = "abcabcabcabc"
    输出: true
    解释: 可由子串 "abc" 重复四次构成。 (或子串 "abcabc" 重复两次构成。)

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/repeated-substring-pattern
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <string>
using namespace std;

// KMP解法后续可以去看 这种字符串匹配的方法具有一定的技巧性
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        // 返回第一个匹配位置的下标 
        // 如果在最后一个位置加一处才发现匹配 即为追加的字符串 说明寻求匹配失败
        return (s + s).find(s, 1) != s.size();
    }
};