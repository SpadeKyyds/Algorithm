/**
 * 难度：简单
 * 字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。

     

    示例 1：

    输入: s = "abcdefg", k = 2
    输出: "cdefgab"
    示例 2：

    输入: s = "lrloseumgh", k = 6
    输出: "umghlrlose"

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <string>
using namespace std;

// 非常巧妙 时间复杂度O(n) 空间复杂度O(1) 原地修改 并未申请额外空间
class Solution {
public:
// 左闭右闭反转字符串片段 s[a, b]
    void reverseString(string& s, int a, int b) {
        char temp;
        while (a < b) {
            temp = s[a];
            s[a] = s[b];
            s[b] = temp;
            ++a;
            --b;
        }
    }

    string reverseLeftWords(string s, int n) {
        reverseString(s, 0, n - 1);
        reverseString(s, n, s.size() - 1);
        reverseString(s, 0, s.size() - 1);
        return s;
    }
};