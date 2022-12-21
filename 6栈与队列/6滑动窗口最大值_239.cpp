/**
 * Hard
 * 
 * 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

    返回 滑动窗口中的最大值 。

     

    示例 1：

    输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
    输出：[3,3,5,5,6,7]
    解释：
    滑动窗口的位置                最大值
    ---------------               -----
    [1  3  -1] -3  5  3  6  7       3
    1 [3  -1  -3] 5  3  6  7       3
    1  3 [-1  -3  5] 3  6  7       5
    1  3  -1 [-3  5  3] 6  7       5
    1  3  -1  -3 [5  3  6] 7       6
    1  3  -1  -3  5 [3  6  7]      7
    示例 2：

    输入：nums = [1], k = 1
    输出：[1]

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/sliding-window-maximum
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include <deque>
#include <vector>
using namespace std;

// time complexity: O(n)
// space complexity: O(k)
class Solution {
public:
    vector<int> result;
    deque<int> slidingWindowQueue;

public:
    void largeTopPileQueuePush(deque<int>& slidingWindowQueue, const int value) {
        // slidingWindowQueue.back() < value 
        // here must be "<", otherwise will lost max value
        while (!slidingWindowQueue.empty() && slidingWindowQueue.back() < value) {
            slidingWindowQueue.pop_back();
        }
        slidingWindowQueue.push_back(value);
    }

    void largeTopPileQueuePop(deque<int>& slidingWindowQueue, const int value) {
        if (!slidingWindowQueue.empty() && value == slidingWindowQueue.front()) {
            slidingWindowQueue.pop_front();
        }
    }

    void getMaxValue(deque<int>& slidingWindowQueue, vector<int>& result) {
        result.push_back(slidingWindowQueue.front());
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i = 0;
        while (i < k) {
            largeTopPileQueuePush(slidingWindowQueue, nums[i]);
            ++i;
        }
        // don't forget to collect max results for every window, especially first one.
        getMaxValue(slidingWindowQueue, result);
        while (i < nums.size()) {
            largeTopPileQueuePush(slidingWindowQueue, nums[i]);
            largeTopPileQueuePop(slidingWindowQueue, nums[i - k]);
            getMaxValue(slidingWindowQueue, result);
            ++i;
        }
        return result;
    }
};

void vectorPrint(vector<int>& vec) {
    for (auto iter = vec.begin(); iter != vec.end(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;
}

int main() {
    Solution solution;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    solution.maxSlidingWindow(nums, k);
    vectorPrint(solution.result);

    return 0;
}