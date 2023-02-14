/**
 * Middle
 * 
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

    机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish”）。

    现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？

    网格中的障碍物和空位置分别用 1 和 0 来表示。

     

    示例 1：


    输入：obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
    输出：2
    解释：3x3 网格的正中间有一个障碍物。
    从左上角到右下角一共有 2 条不同的路径：
    1. 向右 -> 向右 -> 向下 -> 向下
    2. 向下 -> 向下 -> 向右 -> 向右
    示例 2：


    输入：obstacleGrid = [[0,1],[0,0]]
    输出：1
     

    提示：

    m == obstacleGrid.length
    n == obstacleGrid[i].length
    1 <= m, n <= 100
    obstacleGrid[i][j] 为 0 或 1

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/unique-paths-ii
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
using namespace std;

// 时间复杂度O(m*n) 空间复杂度O(m*n)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        // 这题相对于上题有个初始化的细节需要注意
        // 在第一行或者第一列的时候 如果有障碍物 那么后面的位置都需要初始化为0
        vector<vector<int>> dp(m, vector<int>(n, 0)); //这里也可使用默认初始化为0 省略一下写法 当然写出来更易懂
        for (int i = 0, j = 0; j < n; ++j) {
            if (obstacleGrid[0][j] == 0) dp[0][j] = 1;
            else break;
        }
        for (int i = 0, j = 0; i < m; ++i) {
            if (obstacleGrid[i][0] == 0) dp[i][0] = 1;
            else break;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                    if (obstacleGrid[i][j] != 0) dp[i][j] = 0; //如果有障碍物那就不能到达 置0即可
                    else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        return dp[m - 1][n - 1];
    }
};

int main() {
    Solution s;
    vector<vector<int>> obstacleGrid{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    cout << s.uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}