#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> FindGreatestSumOfSubArray(vector<int>& array) {
        vector<int> maxLenVec, tempVec;
        int sum = 0, maxSum = array[0];
        for (int ele : array) {
            sum += ele;
            // 只要前面的和小于0 说明就是在做减法 舍弃掉 从当时元素重新开始计数
            if (sum < 0) {
                tempVec.clear();
                sum = 0;
            } else {
                // 如果不小于0 则将当前元素存入临时数组
                tempVec.push_back(ele);
                // 如果出现了最大和 则更新最大和数组
                if (sum > maxSum) {
                    maxSum = sum;
                    maxLenVec = tempVec;
                    // 如果出现和相等的情况 则比较此时的数组长度和原来数组长度的大小 取长度最大的
                } else if (sum == maxSum) {
                    if (tempVec.size() > maxLenVec.size()) {
                        maxLenVec = tempVec;
                    }
                }
            }
        }
        // 若全负数组 则上面处理结果为空 不符合题意 需要重新遍历原数组 取出最大值
        if (maxLenVec.empty()) {
            int maxVal = array[0];
            for (int ele : array) {
                if (ele > maxVal) maxVal = ele;
            }
            maxLenVec.push_back(maxVal);
        }
        return maxLenVec;
    }
};