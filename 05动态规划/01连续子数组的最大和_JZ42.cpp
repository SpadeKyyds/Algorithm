#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 贪心的思路 时间复杂度O(n) 空间复杂度O(1)
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int>& array) {
        int sum = 0, max = INT16_MIN;
        for (int i = 0; i < array.size(); ++i) {
            sum += array[i];
            max = sum > max ? sum : max;
            if (sum < 0) sum = 0;
        }
        return max;
    }
};

// 动态规划的思路 时间复杂度O(n) 空间复杂度O(1)
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int>& array) {
        int sum = 0, maxSum = array[0];
        for (int i = 0; i < array.size(); ++i) {
            sum = max({sum + array[i], array[i]});
            maxSum = maxSum > sum ? maxSum : sum;
        }
        return maxSum;
    }
};