/**
 * Middle
 * 
 * 有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。

    例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。
    给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。你 不能 重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。

     

    示例 1：

    输入：s = "25525511135"
    输出：["255.255.11.135","255.255.111.35"]
    示例 2：

    输入：s = "0000"
    输出：["0.0.0.0"]
    示例 3：

    输入：s = "101023"
    输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
     

    提示：

    1 <= s.length <= 20
    s 仅由数字组成

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/restore-ip-addresses
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 我的逻辑思维得到了极大锻炼 还是有一定代码能力的
class Solution {
public:
    vector<string> result;
    string path;

public:
    bool validString(string& str) {
        if (str[0] == '0' && str != "0") return false;
        else if (stoll(str, nullptr, 0) < 0 || stoll(str, nullptr, 0) > 255) return false;
        else return true;
    }

    // pointSum其实也是一个剪枝的操作 因为更多的· 的字符串注定就不是一个合法的IP了 没有必要继续递归了!
    void backTracking(string& s, int startIndex, int pointSum) {
        if (pointSum == 3 && startIndex < s.size()) {
            // 这里str是IP地址的第四段 也就是字符串s的最后一截
            string str = s.substr(startIndex, s.size() - startIndex);
            if (validString(str)) result.push_back(path + str);
            return; //这里其实也隐藏有剪枝 遇到不满足条件的第四段也会直接返回上一层递归 不会再去执行底下的for语句
        }
        for (int i = startIndex; i < s.size(); ++i) {
            string str = s.substr(startIndex, i - startIndex + 1);
            // 这里忘了取非 检查后加上即通过了力扣测试 牛逼！
            if (!validString(str)) continue; //剪枝
            auto pos = path.end();
            path.insert(pos, str.begin(), str.end()); // path += str;
            path.insert(path.end(), '.'); // path += ".";
            backTracking(s, i + 1, pointSum + 1);
            path.erase(pos, path.end()); //减去部分字符串用erase
        }
    }

    vector<string> restoreIpAddresses(string s) {
        backTracking(s, 0, 0);
        return result;
    }
};