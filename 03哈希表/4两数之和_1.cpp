/**
 * 难度：简单
 * 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

    你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

    你可以按任意顺序返回答案。

     

    示例 1：

    输入：nums = [2,7,11,15], target = 9
    输出：[0,1]
    解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
    示例 2：

    输入：nums = [3,2,4], target = 6
    输出：[1,2]
    示例 3：

    输入：nums = [3,3], target = 6
    输出：[0,1]

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/two-sum
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

// 此题首先应该想到用哈希结构
// 其次选择map 因为不仅涉及到元素数据 还涉及到下标值
// 选择unordered是因为对顺序没有要求 且允许键值不重复 因为我始终只需要从map中获取一个元素的下标即可
// 不管你数组中有多少个相同数据 我只要存储一个 因为只要从map中获取一个即可
// 最后用元素值作为键值提高了查找效率 键值匹配成功再返回value 即数组下标
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            int sub = target - nums[i];
            if (map.find(sub) != map.end()) {
                return {map.find(sub)->second, i};
            } else {
                map.insert(pair<int, int>(nums[i], i));
            }
        }
        return {};
    }
};