/**
 * Middle
 * 
 * 给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几天后。如果气温在这之后都不会升高，请在该位置用 0 来代替。

     

    示例 1:

    输入: temperatures = [73,74,75,71,69,72,76,73]
    输出: [1,1,4,2,1,1,0,0]
    示例 2:

    输入: temperatures = [30,40,50,60]
    输出: [1,1,1,0]
    示例 3:

    输入: temperatures = [30,60,90]
    输出: [1,1,0]
     

    提示：

    1 <= temperatures.length <= 105
    30 <= temperatures[i] <= 100

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/daily-temperatures
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size());
        stack<int> monotonousStack;
        for (int i = 0; i < temperatures.size(); ++i) {
            if (monotonousStack.empty() || temperatures[i] <= temperatures[monotonousStack.top()]) {
                monotonousStack.push(i);
            } else {
                while (!monotonousStack.empty() && temperatures[i] > temperatures[monotonousStack.top()]) {
                    result[monotonousStack.top()] = i - monotonousStack.top();
                    monotonousStack.pop();
                }
                monotonousStack.push(i);
            }
        }
        return result;
    }
};

// 精简版本
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size());
        stack<int> monotonousStack;
        for (int i = 0; i < temperatures.size(); ++i) {
            while (!monotonousStack.empty() && temperatures[i] > temperatures[monotonousStack.top()]) {
                result[monotonousStack.top()] = i - monotonousStack.top();
                monotonousStack.pop();
            }
            monotonousStack.push(i);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> temperatures{73, 74, 75, 71, 69, 72, 76, 73};
    s.dailyTemperatures(temperatures);
    return 0;
}