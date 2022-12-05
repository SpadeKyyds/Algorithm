/**
 * 难度：简单
 * 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

     

    示例 1：

    输入：s = "We are happy."
    输出："We%20are%20happy."

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/ti-huan-kong-ge-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <string>
using namespace std;

// 申请额外的一片空间 简单直接
// 时间复杂度O(n) 空间复杂度O(n)
class Solution {
public:
    string replaceSpace(string s) {
        int len = s.length();
        string tar;
        for (int i = 0; i < len; ++i) {
            if (s[i] != ' ') {
                tar += s[i];
            } else {
                tar += "%20";
            }
        }
        return tar;
    }
};

// 双指针法 不需要额外申请空间 
// 时间复杂度O(n) 空间复杂度O(1)
class Solution1 {
public:
    string replaceSpace(string s) {
        int count = 0;
        int oldSize = s.size();
        for (auto ch : s) {
            if (ch == ' ') ++count;
        }
        s.resize(oldSize + count*2);
        int newSize = s.size();
        for (int i = oldSize, j = newSize; i < j; --i, --j) {
            if (s[i] != ' ') s[j] = s[i];
            else {
                s[j] = '0';
                s[j - 1] = '2';
                s[j - 2] = '%';
                j -= 2;
            }
        }
        return s;
    }
};