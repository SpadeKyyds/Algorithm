#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;

// // 个人Hash实现 可行 但超时！
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         unordered_map<int, int> u_map;
//         vector<vector<int>> result;
//         int target;
//         for (auto val : nums) {
//             for (auto iter = u_map.begin(); iter != u_map.end(); ++iter) {
//                 target = -val - iter->first;
//                 if (u_map.find(target) != u_map.end() && (target != iter->first || iter->second > 1)) {
//                     result.push_back({val, iter->first, target});
//                 }
//             }
//             if (u_map.find(val) != u_map.end()) {
//                 ++u_map.find(val)->second;
//             } else {
//                 u_map.insert(pair<int, int>(val, 1));
//             }
//         }
//         for (auto iter = result.begin(); iter != result.end(); ++iter) {
//             for (auto it = iter + 1; it != result.end(); ++it) {
//                 if (
//                     (*(iter->begin()) == *(it->begin()) && 
//                     (((*(iter->begin() + 1) == *(it->begin() + 1)) && (*(iter->begin() + 2) == *(it->begin() + 2))) 
//                     || ((*(iter->begin() + 1) == *(it->begin() + 2)) && (*(iter->begin() + 2) == *(it->begin() + 1))))) ||

//                     (*(iter->begin()) == *(it->begin() + 1) && 
//                     (((*(iter->begin() + 1) == *(it->begin())) && (*(iter->begin() + 2) == *(it->begin() + 2))) 
//                     || ((*(iter->begin() + 1) == *(it->begin() + 2)) && (*(iter->begin() + 2) == *(it->begin()))))) ||

//                     (*(iter->begin()) == *(it->begin() + 2) && 
//                     (((*(iter->begin() + 1) == *(it->begin())) && (*(iter->begin() + 2) == *(it->begin() + 1))) 
//                     || ((*(iter->begin() + 1) == *(it->begin() + 1)) && (*(iter->begin() + 2) == *(it->begin())))))
                    
//                     )
                
//                 {
//                     result.erase(it);
//                     --it;
//                 }
//             }
//         }
//         return result;
//     }
// };

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int len = nums.size();
        if (len < 3) return result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len - 2; ++i) {
            // 如果从i 开始后面的数都是大于0的 那就没有继续判断循环的必要了
            if (nums[i] > 0) return result;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1, right = len - 1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] > 0) --right;
                else if (nums[i] + nums[left] + nums[right] < 0) ++left;
                else {
                    result.push_back({nums[i], nums[left], nums[right]});
                    // left < right 这里还要包含此条件 否则可能发生数组下标的越界
                    while (left < right && nums[left] == nums[left + 1]) ++left;
                    while (left < right && nums[right] == nums[right - 1]) --right;
                    ++left;
                    --right;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = s.threeSum(nums);
    return 0;
}