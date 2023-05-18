/**
 * Middle
 * 
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

    给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。



     

    示例 1：

    输入：digits = "23"
    输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
    示例 2：

    输入：digits = ""
    输出：[]
    示例 3：

    输入：digits = "2"
    输出：["a","b","c"]
     

    提示：

    0 <= digits.length <= 4
    digits[i] 是范围 ['2', '9'] 的一个数字。

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/letter-combinations-of-a-phone-number
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 虽然花费了很多时间 但是自己独立写出来了
// 难点：
// 1.字符 字符串 数字 之间的转换  
// 2. 7和9这两个特殊数字  
// 3.映射逻辑以及每个数字取一个字母的单层递归逻辑思考
class Solution {
private:
    vector<string> result;
    string letter;

public:
    void backTracking(string& digits, int startIndex) {
        if (startIndex == digits.size()) {
            result.push_back(letter);
            return;
        }
        int n;
        char ch;
        if (int(digits[startIndex]) - 48 < 8) ch = 'a' + ((int(digits[startIndex]) - 48 - 2)*3);
        else ch = 'a' + ((int(digits[startIndex]) - 48 - 2)*3) + 1;
        if (digits[startIndex] != '9' && digits[startIndex] != '7') n = 3;
        else n = 4;

        for (int j = 0; j < n; ++j) {
            string temp(1, ch);
            letter.append(temp);
            ++ch;
            backTracking(digits, startIndex + 1);
            letter.erase(letter.size() - 1, 1);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (!digits.empty()) backTracking(digits, 0);
        return result;
    }
};

// 卡尔的写法 偷懒构建一个字符串数字映射数组
// string也是一个STL类型 可以通过push pop 增加删除字符
// 字符串可以加上一个字符 但不能减去一个字符 减号没有重载
class Solution1 {
private:
    const string letterMap[10] = {
        "", //0
        "", //1
        "abc", //2
        "def", //3
        "ghi", //4
        "jkl", //5
        "mno", //6
        "pqrs", //7
        "tuv", //8
        "wxyz" //9
    };
    vector<string> result;
    string letter;

public:
    void backTracking(const string& digits, int index) {
        if (index == digits.size()) {
            result.push_back(letter);
            return;
        }
        string temp = letterMap[digits[index] - '0']; //数字字符转换为数字
        for (int i = 0; i < temp.size(); ++i) {
            letter.push_back(temp[i]);
            backTracking(digits, index + 1);
            letter.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (!digits.empty()) backTracking(digits, 0);
        return result;
    }
};