/**
 * Middle
 * 
 * 给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

    candidates 中的每个数字在每个组合中只能使用 一次 。

    注意：解集不能包含重复的组合。 

     

    示例 1:

    输入: candidates = [10,1,2,7,6,1,5], target = 8,
    输出:
    [
    [1,1,6],
    [1,2,5],
    [1,7],
    [2,6]
    ]
    示例 2:

    输入: candidates = [2,5,2,1,2], target = 5,
    输出:
    [
    [1,2,2],
    [5]
    ]
     

    提示:

    1 <= candidates.length <= 100
    1 <= candidates[i] <= 50
    1 <= target <= 30


    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/combination-sum-ii
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 版本一 这题的难点在于树枝的去重简单 树层的去重较难想到 而且不能去重过度
// 准确来说树枝不用去重 只是需要确保一个元素不能多次使用 用startIndex指针即可
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;

public:
    void backTracking(vector<int>& used, vector<int>& candidates, int target, int startIndex) {
        if (target < 0) return;
        else if (target == 0) {
            result.push_back(path);
            return;
        } else {
            for (int i = startIndex; i < candidates.size(); ++i) {
                // 这里其实不是很好理解 这里是树层去重
                if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == 0) continue;
                path.push_back(candidates[i]);
                used[i] = 1;
                // startIndex作用就是树枝去重
                backTracking(used, candidates, target - candidates[i], i + 1);
                path.pop_back();
                used[i] = 0;
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> used(candidates.size(), 0);
        backTracking(used, candidates, target, 0);
        return result;
    }
};

// 版本二
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;

public:
    void backTracking(vector<int>& candidates, int target, int startIndex) {
        if (target < 0) return;
        else if (target == 0) {
            result.push_back(path);
            return;
        } else {
            for (int i = startIndex; i < candidates.size(); ++i) {
                // 这里我觉得这种树层去重更好理解 也节省内存空间
                if (i > startIndex && candidates[i] == candidates[i - 1]) continue;
                path.push_back(candidates[i]);
                backTracking(candidates, target - candidates[i], i + 1);
                path.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); //这题要排个序 才可以完成树层的去重
        backTracking(candidates, target, 0);
        return result;
    }
};