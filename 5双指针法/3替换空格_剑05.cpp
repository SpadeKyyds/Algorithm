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

class Solution {
public:

    string replaceSpace(string s) {
        int count = 0;
        int originLen = s.size();
        for (int i = 0; i < originLen; ++i) {
            if (s[i] == ' ') ++count;
        }
        s.resize(originLen + 2*count);
        int currentLen = s.size();
        int left = originLen - 1, right = currentLen - 1;
        while (left < right) {
            if (s[left] != ' ') s[right--] = s[left--];
            else {
                s[right--] = '0';
                s[right--] = '2';
                s[right--] = '%';
                --left;
            }
        }
        return s;
    }
};