/**
 * Middle
 * 
 * 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。

    你可以按 任何顺序 返回答案。

     

    示例 1：

    输入：n = 4, k = 2
    输出：
    [
    [2,4],
    [3,4],
    [2,3],
    [1,2],
    [1,3],
    [1,4],
    ]
    示例 2：

    输入：n = 1, k = 1
    输出：[[1]]
     

    提示：

    1 <= n <= 20
    1 <= k <= n

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/combinations
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
using namespace std;

// 初步理解回溯：在for循环里面嵌套递归
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;

public:
    void backTracking(int startIndex, int n, int k) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i <= n - (k - path.size()) + 1; ++i) {
            path.push_back(i);
            backTracking(i + 1, n, k);
            path.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        backTracking(1, n, k);
        return result;
    }
};