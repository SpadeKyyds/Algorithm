/**
 * 难度：中等
 * 给定一个含有 n 个正整数的数组和一个正整数 target 。

    找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

     

    示例 1：

    输入：target = 7, nums = [2,3,1,2,4,3]
    输出：2
    解释：子数组 [4,3] 是该条件下的长度最小的子数组。
    示例 2：

    输入：target = 4, nums = [1,4,4]
    输出：1
    示例 3：

    输入：target = 11, nums = [1,1,1,1,1,1,1,1]
    输出：0

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/minimum-size-subarray-sum
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>
using namespace std;

// 暴力解法，时间复杂度O(n^2)，空间复杂度O(1)
// 造成时间复杂度为O(n^2)的原因是终止指针发生了回溯，增加了不必要的操作
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i, j, sum, count, minLen = 0;
        for (i = 0; i < nums.size(); ++i) {
            j = i; sum = 0; count = 0;
            while (j < nums.size()) {
                ++count;
                if (minLen != 0 && count >= minLen) {
                    break;
                }
                sum += nums[j];
                if (sum >= target && ((count < minLen) || (minLen == 0))) {
                    minLen = count;
                    break;
                }
                ++j;
            }
        }
        return minLen;
    }
};

// 在知晓滑动窗口后自己写出的代码，少部分数组序列不能满足，设计复杂，未考虑好边界条件，究其原因为掌握不透彻
class Solution1 {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int head = 0, sum = 0, minLen = INT32_MAX;
        for (int tail = 0; tail < nums.size();) {
            while (sum < target && tail < nums.size()) {
                sum += nums[tail];
                ++tail;
            }
            if (sum >= target) {
                minLen = minLen <= (tail - head) ? minLen : (tail - head);
            }
            while (sum >= target) {
                sum -= nums[head];
                ++head;
                if (sum >= target) {
                    --minLen;
                } else {
                    // --head;
                }
            }
        }
        return minLen == INT32_MAX ? 0 : minLen;
    }
};

/**
 * 滑动窗口思想，不同于我前面的思想的是终止指针不会回溯，从而时间复杂度为O(n)，空间复杂度仍为O(1)
 * 1.只需定义一个for循环，当连续序列的元素和小于target时候，终止指针不停后移，sum不断增加即可
 * 2.当sum大于等于目标值时，此时更新满足条件的最小窗口长度，起始指针此时也要后移，并在一个while循环里继续判断
 *   缩小后的窗口内元素值是否大于等于target，若满足要求，继续缩短最小窗口长度，起始指针继续后移
 * 3.最后终止指针遍历完数组即可返回最小窗口长度，若最小长度仍为最大值，说明从未进入sum>=target判断语句，窗口长为0
*/
class Solution2 {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int head = 0, sum = 0, winLen = 0, minLen = INT32_MAX;
        for (int tail = 0; tail < nums.size(); ++tail) {
            sum += nums[tail];
            while (sum >= target) {
                winLen = tail - head + 1;
                minLen = minLen <= winLen ? minLen : winLen;
                sum -= nums[head++];
            }
        }
        return minLen == INT32_MAX ? 0 : minLen;
    }
};

int main() {
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;
    Solution s;
    Solution2 ss;
    cout << ss.minSubArrayLen(target, nums) << endl;

    vector<int> nums1 = {1, 4, 4};
    int target1 = 4;
    Solution s1;
    Solution2 ss1;
    cout << ss1.minSubArrayLen(target1, nums1) << endl;

    vector<int> nums2 = {1, 1, 1, 1, 1, 1, 1, 1};
    int target2 = 11;
    Solution s2;
    Solution2 ss2;
    cout << ss2.minSubArrayLen(target2, nums2) << endl;

    return 0;
}