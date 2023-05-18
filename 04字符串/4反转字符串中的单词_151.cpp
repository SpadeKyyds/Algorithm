/**
 * 难度：中等
 * 给你一个字符串 s ，请你反转字符串中 单词 的顺序。

    单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。

    返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。

    注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。

    

    示例 1：

    输入：s = "the sky is blue"
    输出："blue is sky the"
    示例 2：

    输入：s = "  hello world  "
    输出："world hello"
    解释：反转后的字符串中不能存在前导空格和尾随空格。
    示例 3：

    输入：s = "a good   example"
    输出："example good a"
    解释：如果两个单词间有多余的空格，反转后的字符串需要将单词间的空格减少到仅有一个。
    

    提示：

    1 <= s.length <= 104
    s 包含英文大小写字母、数字和空格 ' '
    s 中 至少存在一个 单词
 * 
*/

#include <iostream>
#include <string>
using namespace std;

/**
 * 参照卡尔的思路：
 * 1.删除多余的空格
 * 2.整体翻转字符串
 * 3.翻转每个单词
*/

// 时间复杂度O(n) 空间复杂度O(1) 此题具有一定思考意义 后期重点看！
class Solution {
public:
    // 翻转字符串s区间[start, end]内的字符串片段 
    void reverseString(string& s, int start, int end) {
        char temp;
        while (start < end) {
            temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            ++start;
            --end;
        }
    }

// 精简的代码 大大的智慧
    void deleteExtraSpace(string& s) {
        int slow = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ') {
                // 对于非开头的单词 在单词前加入一个空格 巧妙利用slow指针
                if (slow != 0) s[slow++] = ' ';
                // i < s.size()必须要有 否则会发生数组下标越界
                while (i < s.size() && s[i] != ' ') s[slow++] = s[i++];
            }
        }
        s.resize(slow);
    }
    
// 我的写法 时间复杂度也是O(n) 没啥问题
    // string reverseWords(string s) {
    //     deleteExtraSpace(s);
    //     reverseString(s, 0, s.size() - 1);
    //     for (int i = 0; i < s.size(); ++i) {
    //         int start = i;
    //         while (i < s.size() && s[i] != ' ') ++i;
    //         int end = i - 1;
    //         reverseString(s, start, end);
    //     }
    //     return s;
    // }
    
// 卡尔的写法 更加简洁直观明了 不需要另起一个while循环 直接利用for循环就可以
    string reverseWords(string s) {
        deleteExtraSpace(s);
        reverseString(s, 0, s.size() - 1);
        int start = 0;
        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') {
                reverseString(s, start, i - 1);
                start = i + 1;
            }
        }
        return s;
    }
};