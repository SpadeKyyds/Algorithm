/**
 * 难度：简单
 * 给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。

     

    示例 1：

    输入：nums1 = [1,2,2,1], nums2 = [2,2]
    输出：[2]
    示例 2：

    输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
    输出：[9,4]
    解释：[4,9] 也是可通过的

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/intersection-of-two-arrays
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

// 使用unordered_set解决本题
// 当数据量较大时数组就不再适用，无序且无重复用unordered_set，有序无重复用set，有序有重复用过multiset
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result_set; //这里使用unordered_set数据结构直接规避了相同数值的情况
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for (auto& num : nums2) {
            if (nums_set.find(num) != nums_set.end()) {
                result_set.insert(num);
            } 
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};