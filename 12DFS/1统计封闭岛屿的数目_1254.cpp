/**
 * Middle
 * 
 * 二维矩阵 grid 由 0 （土地）和 1 （水）组成。岛是由最大的4个方向连通的 0 组成的群，封闭岛是一个 完全 由1包围（左、上、右、下）的岛。

    请返回 封闭岛屿 的数目。

     

    示例 1：



    输入：grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
    输出：2
    解释：
    灰色区域的岛屿是封闭岛屿，因为这座岛屿完全被水域包围（即被 1 区域包围）。
    示例 2：



    输入：grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
    输出：1
    示例 3：

    输入：grid = [[1,1,1,1,1,1,1],
                 [1,0,0,0,0,0,1],
                 [1,0,1,1,1,0,1],
                 [1,0,1,0,1,0,1],
                 [1,0,1,1,1,0,1],
                 [1,0,0,0,0,0,1],
                [1,1,1,1,1,1,1]]
    输出：2
     

    提示：

    1 <= grid.length, grid[0].length <= 100
    0 <= grid[i][j] <=1

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/number-of-closed-islands
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int count = 0;
        for (int i = 1; i < rows - 1; i++) {
            for (int j = 1; j < cols - 1; j++) {
                if (grid[i][j] == 0) {
                    if (dfs(grid, i, j)) {
                        ++count;
                    }
                }
            }
        }
        return count;
    }
    
    bool dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
            return false;
        }
        if (grid[i][j] == 1) {
            return true;
        }
        grid[i][j] = 1; //此标记表示已经访问过
        bool up = dfs(grid, i - 1, j);
        bool down = dfs(grid, i + 1, j);
        bool left = dfs(grid, i, j - 1);
        bool right = dfs(grid, i, j + 1);
        return up && down && left && right;
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid {{1,1,1,1,1,1,1,0},
                              {1,0,0,0,0,1,1,0},                
                              {1,0,1,0,1,1,1,0},
                              {1,0,0,0,0,1,0,1},
                              {1,1,1,1,1,1,1,0}};
    cout << s.closedIsland(grid) << endl;
    return 0;
}