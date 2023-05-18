/**
 * 难度：简单
 * 给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。

    如果剩余字符少于 k 个，则将剩余字符全部反转。
    如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
     

    示例 1：

    输入：s = "abcdefg", k = 2
    输出："bacdfeg"
    示例 2：

    输入：s = "abcd", k = 2
    输出："bacd"

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/reverse-string-ii
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <string>
using namespace std;

// 逻辑严密，一次性通过 时间复杂度O(n)
class Solution {
public:
    void swapCharacter(char& a, char& b) {
        char temp;
        temp = a;
        a = b;
        b = temp;
    }

    // 反转s的下标为[i,j]的部分字符串
    void reverse(string& s, int i, int j) {
        while (i < j) {
            swapCharacter(s[i], s[j]);
            ++i;
            --j;
        }
    }
    // 自己实现的 比较复杂 参考下面carl的 简洁
    // string reverseStr(string s, int k) {
    //     int a, b, i = 0;
    //     while (i < s.length()) {
    //         a = i;
    //         if (i + k <= s.length()) b = i + k - 1;
    //         else b = s.length() - 1;
    //         reverse (s, a, b);
    //         i += 2*k;
    //     }
    //     return s;
    // }

    string reverseStr(string s, int k) {
        for (int i = 0; i < s.length(); i += 2*k) {
            // 秉承反转函数 左闭右开的理念 这里使用i + k <= s.length()
            if (i + k <= s.length()) reverse(s, i, i + k - 1); //因为自己实现的是左闭右闭 所以这减一
            else reverse(s, i, s.length() - 1);
        }
        return s;
    }
};