/**
 * Middle
 * 
 * 给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。

     

    示例 1:

    输入: nums = [1,1,1,2,2,3], k = 2
    输出: [1,2]
    示例 2:

    输入: nums = [1], k = 1
    输出: [1]
     

    提示：

    1 <= nums.length <= 105
    k 的取值范围是 [1, 数组中不相同的元素的个数]
    题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/top-k-frequent-elements
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
private:
    unordered_map<int, int> numsMap;
    vector<int> result;
    deque<pair<int, int>> smallTopPileQueue;

public:
    // small top pile queue generated
    void pushSmallTopPileQueue(deque<pair<int, int>>& smallTopPileQueue, pair<int, int> element) {
        int count = 0;
        if (smallTopPileQueue.empty() || smallTopPileQueue.back().second <= element.second) {
            smallTopPileQueue.push_back(element);
        } else if (smallTopPileQueue.front().second >= element.second) {
            smallTopPileQueue.push_front(element);
        } else {
            while (smallTopPileQueue.back().second > element.second) {
                smallTopPileQueue.push_front(smallTopPileQueue.back());
                smallTopPileQueue.pop_back();
                ++count;
            }
            smallTopPileQueue.push_back(element);
            while (count--) {
                smallTopPileQueue.push_back(smallTopPileQueue.front());
                smallTopPileQueue.pop_front();
            }
        }
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        // unorder_map generated
        for (auto key : nums) {
            auto iter = numsMap.find(key);
            if (iter != numsMap.end()) ++iter->second;
            else numsMap.insert(pair<int, int> (key, 1));
        }
        // k size small top pile queue generated
        for (auto element : numsMap) {
            if (smallTopPileQueue.size() < k) pushSmallTopPileQueue(smallTopPileQueue, element);
            else if (smallTopPileQueue.size() == k && element.second <= smallTopPileQueue.front().second) continue;
            else {
                pushSmallTopPileQueue(smallTopPileQueue, element);
                smallTopPileQueue.pop_front();
            }
        }
        // acquire elements that appear more than k times and push them in a vector
        while (!smallTopPileQueue.empty()) {
            result.push_back(smallTopPileQueue.back().first);
            smallTopPileQueue.pop_back();
        }
        return result;
    }
};