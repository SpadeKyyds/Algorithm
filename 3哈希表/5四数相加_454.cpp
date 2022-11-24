/** 
 * 难度：中等
 * 给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足：

    0 <= i, j, k, l < n
    nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
     

    示例 1：

    输入：nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
    输出：2
    解释：
    两个元组如下：
    1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
    2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0
    示例 2：

    输入：nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
    输出：1

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/4sum-ii
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

// 这题其实大体思路我已经想到了 只是陷入到具体选择什么map的怪圈了 
// 题目中并不需要知道具体是什么元组 只是需要得到元组的数量即可
// 因此决定了本题可以使用unordered_map 并且value值存key值出现的次数即可
// 时间复杂度O(n^2) 空间复杂度O(1)
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> map;
        int sum, count = 0;
        for (int i = 0; i < nums1.size(); ++i) {
            for (int j = 0; j < nums2.size(); ++j) {
                sum = nums1[i] + nums2[j];
                if (map.find(sum) != map.end()) {
                    ++map[sum];
                } else {
                    map.insert(pair<int, int>(sum, 1));
                }
            }
        }
        for (int i = 0; i < nums3.size(); ++i) {
            for (int j = 0; j < nums4.size(); ++j) {
                sum = -(nums3[i] + nums4[j]);
                if (map.find(sum) != map.end()) {
                    count += map[sum];
                }
            }
        }
        return count;
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {1, 2}, nums2 = {-2, -1}, nums3 = {-1, 2}, nums4 = {0, 2};
    cout << "There are " << s.fourSumCount(nums1, nums2, nums3, nums4) << 
    " tuples satisfy four numbers' sum equal to zero." << endl;
    return 0;
}