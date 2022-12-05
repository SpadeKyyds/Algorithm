/**
 * 难度：中等
 * 给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。如果 needle 不是 haystack 的一部分，则返回  -1 。

     

    示例 1：

    输入：haystack = "sadbutsad", needle = "sad"
    输出：0
    解释："sad" 在下标 0 和 6 处匹配。
    第一个匹配项的下标是 0 ，所以返回 0 。
    示例 2：

    输入：haystack = "leetcode", needle = "leeto"
    输出：-1
    解释："leeto" 没有在 "leetcode" 中出现，所以返回 -1 。

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <string>
using namespace std;

// 这种以0开始的KMP算法的写法要注意 以后就用这种即可
// 时间复杂度O(n + m) 相对于暴力解法的O(n*m) 效率极大提高
class Solution {
public:
    void getNextArray(string needle, int *next) {
        int i = 0, j = -1;
        next[0] = -1;
        while (i < needle.length() - 1) {
            if (j == -1 || needle[i] == needle[j]) {
                ++i;
                ++j;
                next[i] = j;
            } else {
                j = next[j];
            }
        }
    }

    int strStr(string haystack, string needle) {
        int next[needle.size()], i = 0, j = 0;
        // 为什么这里要先用个变量把字符串的长度存起来才对呢？
        int len1 = haystack.length();
        int len2 = needle.length();
        getNextArray(needle, next);
        while (i < len1 && j < len2) {
            if (j == -1 || haystack[i] == needle[j]) {
                ++i;
                ++j;
            } else {
                j = next[j];
            }
        }
        if (j == len2) return i - j;
        else return -1;
    }
};

int main() {
    Solution s;
    string haystack = "mississippi";
    string needle = "issip";
    cout << s.strStr(haystack, needle) << endl;
    return 0;
}