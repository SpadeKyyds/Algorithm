/**
 * 简单
 * 
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

    有效字符串需满足：

    左括号必须用相同类型的右括号闭合。
    左括号必须以正确的顺序闭合。
    每个右括号都有一个对应的相同类型的左括号。
     

    示例 1：

    输入：s = "()"
    输出：true
    示例 2：

    输入：s = "()[]{}"
    输出：true
    示例 3：

    输入：s = "(]"
    输出：false

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/valid-parentheses
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> bracketStack;
        if (s.size() % 2 != 0) return false;
        for (auto ch : s) {
            // using single quotes to enclose the bracket will avoid brackets matching
            if (ch == '(') bracketStack.push(')');
            else if (ch == '[') bracketStack.push(']');
            else if (ch == '{') bracketStack.push('}');
            // right bracket is excess or brackets are not matching
            else if (bracketStack.empty() || bracketStack.top() != ch) return false;
            else bracketStack.pop();
        }
        // left bracket is excess, an unempty stack will be returned
        return bracketStack.empty();
    }
};

int main() {
    Solution solution;
    string s = "()";
    cout << solution.isValid(s) << endl;
    return 0;
}