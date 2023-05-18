/**
 * Hard
 * 
 * n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。

    你需要按照以下要求，给这些孩子分发糖果：

    每个孩子至少分配到 1 个糖果。
    相邻两个孩子评分更高的孩子会获得更多的糖果。
    请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。

     

    示例 1：

    输入：ratings = [1,0,2]
    输出：5
    解释：你可以分别给第一个、第二个、第三个孩子分发 2、1、2 颗糖果。
    示例 2：

    输入：ratings = [1,2,2]
    输出：4
    解释：你可以分别给第一个、第二个、第三个孩子分发 1、2、1 颗糖果。
        第三个孩子只得到 1 颗糖果，这满足题面中的两个条件。

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/candy
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 这题难的是思路 想象不到 代码写起来还是十分简洁的
class Solution {
public:
    int candy(vector<int>& ratings) {
        int totalCandy = 0;
        vector<int> curCandy(ratings.size(), 1);
        // 这种两边的情况 分两个循环两次比较 如果一次比较的话不行 
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i - 1]) curCandy[i] = curCandy[i - 1] + 1;
        }
        for (int j = ratings.size() - 1; j >= 0; --j) {
            if (j > 0 && ratings[j - 1] > ratings[j]) curCandy[j - 1] = max(curCandy[j] + 1, curCandy[j - 1]);
            totalCandy += curCandy[j];
        }
        return totalCandy;
    }
};