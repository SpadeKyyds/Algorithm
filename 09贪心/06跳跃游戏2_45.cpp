/**
 * Middle
 * 
 * 给定一个长度为 n 的 0 索引整数数组 nums。初始位置为 nums[0]。

    每个元素 nums[i] 表示从索引 i 向前跳转的最大长度。换句话说，如果你在 nums[i] 处，你可以跳转到任意 nums[i + j] 处:

    0 <= j <= nums[i] 
    i + j < n
    返回到达 nums[n - 1] 的最小跳跃次数。生成的测试用例可以到达 nums[n - 1]。

     

    示例 1:

    输入: nums = [2,3,1,1,4]
    输出: 2
    解释: 跳到最后一个位置的最小跳跃数是 2。
         从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
    示例 2:

    输入: nums = [2,3,0,1,4]
    输出: 2

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/jump-game-ii
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int current = 0, next = 0, result = 0;
        // 这里要注意 范围是i < nums.size()
        for (int i = 0; i < nums.size(); ++i) {
            next = max(next, i + nums[i]);
            // 这题的思路有点绕 当i触碰到current边界 且边界还触碰不到终点时 就可以进入下一层的跳跃
            if (i == current && current < nums.size() - 1) {
                ++result;
                current = next;
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {7, 0, 9, 6, 9, 6, 1, 7, 9, 0, 1, 2, 9, 0, 3};
    cout << s.jump(nums) << "" << endl;
    return 0;
}