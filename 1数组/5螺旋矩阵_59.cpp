/**
 * 难度：中等
 * 给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。

     

    示例 1：


    输入：n = 3
    输出：[[1,2,3],[8,9,4],[7,6,5]]
    示例 2：

    输入：n = 1
    输出：[[1]]

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/spiral-matrix-ii
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
using namespace std;

// 这个题目最需要注意的是：循环不变量原则
// 时间复杂度O(n^2) 空间复杂度O(1)
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // vector的底层实现是array，严格来说vector是容器，不是array
        // 数组元素只能覆盖，不能删除
        vector<vector<int>> matrix(n, vector<int>(n));
        int count = 0, loop = n/2;
        int i, j; //i为横向坐标，而j为纵向坐标
        //n为数组大小，而下标起始为0，从而边界为n-1，不是n
        int xStart = 0, yStart = 0, xEnd = n - 1, yEnd = n - 1;
        while (loop--) {
            for (i = xStart, j = yStart; j < yEnd; ++j) {
                matrix[i][j] = ++count;
            }
            for (i = xStart, j = yEnd; i < xEnd; ++i) {
                matrix[i][j] = ++count;
            }
            for (i = xEnd, j = yEnd; j > yStart; --j) {
                matrix[i][j] = ++count;
            }
            for (i = xEnd, j = yStart; i > xStart; --i) {
                matrix[i][j] = ++count;
            }
            ++xStart;
            ++yStart;
            --xEnd;
            --yEnd;
        }
        // 如果n为奇数，最中间一个位置的数要单独处理
        if (n%2) {
            matrix[n/2][n/2] = ++count; //这里是n/2即为最中间位置，不需要加1
        }
        return matrix;
    }
};

void print(vector<vector<int>>& matrix, int n) {
    int i, j;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    Solution s;
    vector<vector<int>> matrix;
    int n = 3;
    matrix = s.generateMatrix(n);
    print(matrix, n);

    return 0;
}