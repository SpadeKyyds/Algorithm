/**
 * Middle
 * 
 * 有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，那么城市 a 与城市 c 间接相连。

    省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。

    给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，而 isConnected[i][j] = 0 表示二者不直接相连。

    返回矩阵中 省份 的数量。

     

    示例 1：


    输入：isConnected = [[1,1,0],[1,1,0],[0,0,1]]
    输出：2
    示例 2：


    输入：isConnected = [[1,0,0],[0,1,0],[0,0,1]]
    输出：3
     

    提示：

    1 <= n <= 200
    n == isConnected.length
    n == isConnected[i].length
    isConnected[i][j] 为 1 或 0
    isConnected[i][i] == 1
    isConnected[i][j] == isConnected[j][i]

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/number-of-provinces
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
    
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 即为求解连通分量的数目 首先采用DFS的方法
class Solution {
public:
    void dfsCities(vector<vector<int>>& isConnected, vector<bool>& visited, int i) {
        visited[i] = true;
        for (int j = 0; j < isConnected.size(); ++j) {
            if (!visited[j] && isConnected[i][j] == 1) {
                dfsCities(isConnected, visited, j);
            }
        } 
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces = 0;
        vector<bool> visited(isConnected.size(), false); //用于标记是否已经被访问过
        for (int i = 0; i < isConnected.size(); ++i) {
            if (!visited[i]) {
                dfsCities(isConnected, visited, i);
                provinces++; // 注意这里要放到if判断语句里面才行
            }
        }
        return provinces;
    }
};

// BFS广度优先遍历解法 
class Solution1 {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size(), false); // 初始化一个辅助数组 表示该节点是否被遍历过
        queue<int> nodeQueue; // 初始化一个辅助队列 用于存放节点的下标
        int provinces = 0;
        for (int i = 0; i < isConnected.size(); ++i) {
            if (!visited[i]) {
                nodeQueue.push(i);
                visited[i] = true;
                ++provinces;
            }
            while (!nodeQueue.empty()) {
                for (int j = 0; j < isConnected.size(); ++j) {
                    if (!visited[j] && isConnected[nodeQueue.front()][j] == 1) {
                        nodeQueue.push(j);
                        visited[j] = true;
                    }
                }
                nodeQueue.pop();
            }
        }
        return provinces;
    }
};

int main() {
    Solution1 s;
    vector<vector<int>> isConnected {{1,1,0}, {1,1,0}, {0,0,1}};
    cout << s.findCircleNum(isConnected) << endl;
    return 0;
}