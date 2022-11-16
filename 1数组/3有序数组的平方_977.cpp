/**
 * 难度：简单
 * 给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。

 

    示例 1：

    输入：nums = [-4,-1,0,3,10]
    输出：[0,1,9,16,100]
    解释：平方后，数组变为 [16,1,0,9,100]
    排序后，数组变为 [0,1,9,16,100]
    示例 2：

    输入：nums = [-7,-3,2,3,11]
    输出：[4,9,9,49,121]

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/squares-of-a-sorted-array
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
using namespace std;

// 时间复杂度O(n) 空间复杂度O(1)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // 这里vector<int> array = nums 等价于 vector<int> array(nums)
        // array中包含nums中所有元素的副本 相当于重新申请了一片内存空间，并将nums完全拷贝过来，包含所有元素及大小
        vector<int> array = nums; //vector的用法如何？
        int left = 0, right = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (array[right]*array[right] >= array[left]*array[left]) {
                nums[i] = array[right]*array[right];
                --right;
            } else {
                nums[i] = array[left]*array[left];
                ++left;
            }
        }
        return nums;
    }
};

void print(vector<int>& nums) {
    for (auto i = nums.begin(); i != nums.end(); ++i) {
        cout << *i << " ";
    }
}

int main() {
    Solution s;
    vector<int> nums = {-4,-1,0,3,10};
    s.sortedSquares(nums);
    print(nums);

    return 0;
}