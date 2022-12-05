#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;

// 个人Hash实现 可行 但超时！
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> u_map;
        vector<vector<int>> result;
        int target;
        for (auto val : nums) {
            for (auto iter = u_map.begin(); iter != u_map.end(); ++iter) {
                target = -val - iter->first;
                if (u_map.find(target) != u_map.end() && (target != iter->first || iter->second > 1)) {
                    result.push_back({val, iter->first, target});
                }
            }
            if (u_map.find(val) != u_map.end()) {
                ++u_map.find(val)->second;
            } else {
                u_map.insert(pair<int, int>(val, 1));
            }
        }
        for (auto iter = result.begin(); iter != result.end(); ++iter) {
            for (auto it = iter + 1; it != result.end(); ++it) {
                if (
                    (*(iter->begin()) == *(it->begin()) && 
                    (((*(iter->begin() + 1) == *(it->begin() + 1)) && (*(iter->begin() + 2) == *(it->begin() + 2))) 
                    || ((*(iter->begin() + 1) == *(it->begin() + 2)) && (*(iter->begin() + 2) == *(it->begin() + 1))))) ||

                    (*(iter->begin()) == *(it->begin() + 1) && 
                    (((*(iter->begin() + 1) == *(it->begin())) && (*(iter->begin() + 2) == *(it->begin() + 2))) 
                    || ((*(iter->begin() + 1) == *(it->begin() + 2)) && (*(iter->begin() + 2) == *(it->begin()))))) ||

                    (*(iter->begin()) == *(it->begin() + 2) && 
                    (((*(iter->begin() + 1) == *(it->begin())) && (*(iter->begin() + 2) == *(it->begin() + 1))) 
                    || ((*(iter->begin() + 1) == *(it->begin() + 1)) && (*(iter->begin() + 2) == *(it->begin())))))
                    
                    )
                
                {
                    result.erase(it);
                    --it;
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