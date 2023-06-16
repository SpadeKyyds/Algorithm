#include <iostream>
#include <vector>
using namespace std;

// 充分利用数组有序的特性 从左下角或者右上角开始寻找
// 这个方式方法很典型 注意记忆 时间复杂度为O(n + m) 空间复杂度为O(1)
class Solution {
public:
    bool Find(int target, vector<vector<int>>& array) {
        if (array.size() == 0) return false;
        // row代表行 col代表列
        int row = 0, col = array[0].size() - 1;
        while (row < array.size() && col >= 0) {
            if (array[row][col] > target) --col;
            else if (array[row][col] < target) ++row;
            else return true;
        }
        return false;
    }
};