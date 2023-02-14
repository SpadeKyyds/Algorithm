/**
 * Middle
 * 
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

    机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。

    问总共有多少条不同的路径？

     

    示例 1：


    输入：m = 3, n = 7
    输出：28
    示例 2：

    输入：m = 3, n = 2
    输出：3
    解释：
    从左上角开始，总共有 3 条路径可以到达右下角。
    1. 向右 -> 向下 -> 向下
    2. 向下 -> 向下 -> 向右
    3. 向下 -> 向右 -> 向下
    示例 3：

    输入：m = 7, n = 3
    输出：28
    示例 4：

    输入：m = 3, n = 3
    输出：6
     

    提示：

    1 <= m, n <= 100
    题目数据保证答案小于等于 2 * 109


    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/unique-paths
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
using namespace std;

// 自己写出来了 牛逼！
// 时间复杂度O(m*n) 空间复杂度O(m*n)
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) return 1;
        // 初始化为1 其实只要初始化第一行和第一列就可以 这种写法简洁
        vector<vector<int>> grid(m, vector<int>(n, 1));
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                // 这里因为每次只能走一步 且不能拐弯 所以总的次数为
                // 到达左边格子路径数加到达右边格子路径数
                grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
            }
        }
        return grid[m - 1][n - 1];
    }
};