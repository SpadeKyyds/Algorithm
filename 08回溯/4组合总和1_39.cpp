/**
 * Middle
 * 
 * 给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。

    candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。 

    对于给定的输入，保证和为 target 的不同组合数少于 150 个。

     

    示例 1：

    输入：candidates = [2,3,6,7], target = 7
    输出：[[2,2,3],[7]]
    解释：
    2 和 3 可以形成一组候选，2 + 2 + 3 = 7 。注意 2 可以使用多次。
    7 也是一个候选， 7 = 7 。
    仅有这两种组合。
    示例 2：

    输入: candidates = [2,3,5], target = 8
    输出: [[2,2,2,2],[2,3,3],[3,5]]
    示例 3：

    输入: candidates = [2], target = 1
    输出: []
     

    提示：

    1 <= candidates.length <= 30
    2 <= candidates[i] <= 40
    candidates 的所有元素 互不相同
    1 <= target <= 40

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/combination-sum
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> result;
public:
    void backTracking(vector<int>& path, vector<int>& candidates, int startIndex, int target) {
        if (target < 0) return;
        else if (target == 0) {
            result.push_back(path);
            return;
        } else {
            for (int i = startIndex; i < candidates.size(); ++i) {
                path.push_back(candidates[i]);
                // 注意这里的下标从i开始就可以完成一个去重的操作 很妙
                // 元素可以重复就从i开始 不可重就从i + 1开始
                backTracking(path, candidates, i, target - candidates[i]);
                path.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        backTracking(path, candidates, 0, target);
        return result;
    }
};

void printResult(vector<vector<int>> result) {
    for (auto iter = result.begin(); iter != result.end(); ++iter) {
        for (auto i = (*iter).begin(); i != (*iter).end(); ++i) {
            cout << *i << ", ";
        }
        cout << endl;
    }
}

int main() {
    Solution s;
    vector<int> candidate = {2, 3, 6, 7};
    int target = 7;
    printResult(s.combinationSum(candidate, target));
    return 0;
}