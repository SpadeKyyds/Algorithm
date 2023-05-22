/**
 * 难度：简单
 * 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

    注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。

     

    示例 1:

    输入: s = "anagram", t = "nagaram"
    输出: true
    示例 2:

    输入: s = "rat", t = "car"
    输出: false

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/valid-anagram
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 哈希表方法 映射函数为哈希函数 使用的是数组这种数据结构
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        vector<int> table(26, 0);
        for (auto ch : s) {
            ++table[ch - 'a'];
        }
        for (auto ch : t) {
            --table[ch - 'a'];
            if (table[ch - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};

// 排序的方法 如果两个字符串是异位词 则排序后相等
// 时间复杂度O(nlogn)   排序 + 比较 O(nlogn + n) = O(nlogn)
// 空间复杂度O(logn)来源于排序
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};