/**
 * Middle
 * 
 * 找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：

    只使用数字1到9
    每个数字 最多使用一次 
    返回 所有可能的有效组合的列表 。该列表不能包含相同的组合两次，组合可以以任何顺序返回。

     

    示例 1:

    输入: k = 3, n = 7
    输出: [[1,2,4]]
    解释:
    1 + 2 + 4 = 7
    没有其他符合的组合了。
    示例 2:

    输入: k = 3, n = 9
    输出: [[1,2,6], [1,3,5], [2,3,4]]
    解释:
    1 + 2 + 6 = 9
    1 + 3 + 5 = 9
    2 + 3 + 4 = 9
    没有其他符合的组合了。
    示例 3:

    输入: k = 4, n = 1
    输出: []
    解释: 不存在有效的组合。
    在[1,9]范围内使用4个不同的数字，我们可以得到的最小和是1+2+3+4 = 10，因为10 > 1，没有有效的组合。
     

    提示:

    2 <= k <= 9
    1 <= n <= 60

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/combination-sum-iii
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;

public:
    void backTracking(int startIndex, int& k, int& n) {
        if (n == 0 && path.size() == k) {
            result.push_back(path);
            return;
        }
        // 这里我的剪枝操作十分充分 应该已经是最大剪枝了
        for (int i = startIndex; n > 0 && path.size() < k && i <= 10 - (k - path.size()); ++i) {
            path.push_back(i);
            n -= i;
            backTracking(i + 1, k, n);
            path.pop_back();
            n += i; //这里不要忘记对n的回溯
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        backTracking(1, k, n);
        return result;
    }
};

void printResult(vector<vector<int>> result) {
    for (auto iter = result.begin(); iter != result.end(); ++iter) {
        for (auto i = (*iter).begin(); i != (*iter).end(); ++i) {
            cout << *i << " ";
        }
        cout << endl;
    }
}

int main() {
    Solution s;
    int k = 3, n = 9;
    printResult(s.combinationSum3(k, n));
    return 0;
}