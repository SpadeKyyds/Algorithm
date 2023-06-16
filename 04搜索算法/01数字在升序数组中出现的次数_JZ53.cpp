#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int GetNumberOfK(vector<int>& nums, int k) {
        if (nums.size() == 0) return 0;
        int res = 0;
        // 先使用二分查找法找到目标元素对应的下标
        int first = 0, last = nums.size();
        int mid = 0;
        // 注意：这里用< 那就是边缘取不到 last要为last = nums.size()
        while (first < last) {
            mid = (first + last) / 2;
            if (nums[mid] < k) {
                first = mid + 1; //这里的fist更新 注意为取得到的值
            } else if (nums[mid] > k) {
                last = mid; //同时因为边缘取不到 这里的last变化也要为取不到的值
            } else {
                break;
            }
        }
        if (nums[mid] == k) {
            int left = mid, right = mid;
            while (nums[left--] == k) ++res;
            while (nums[++right] == k) ++res;
        } else {
            res = 0;
        }
        return res;
    }
};