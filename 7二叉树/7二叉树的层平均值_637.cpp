/**
 * Easy
 * 
 * 给定一个非空二叉树的根节点 root , 以数组的形式返回每一层节点的平均值。与实际答案相差 10-5 以内的答案可以被接受。

     

    示例 1：



    输入：root = [3,9,20,null,null,15,7]
    输出：[3.00000,14.50000,11.00000]
    解释：第 0 层的平均值为 3,第 1 层的平均值为 14.5,第 2 层的平均值为 11 。
    因此返回 [3, 14.5, 11] 。
    示例 2:



    输入：root = [3,9,20,15,7]
    输出：[3.00000,14.50000,11.00000]

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/average-of-levels-in-binary-tree
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        queue<TreeNode*> nodeQueue;
        TreeNode* node = root, *popNode;
        int size;
        if (node == nullptr) return result;
        nodeQueue.emplace(node);
        size = nodeQueue.size(); //using size to control node pop numbers on every level
        while (!nodeQueue.empty()) {
            int count = 0;
            double sum = 0;
            while (size--) {
                popNode = nodeQueue.front();
                nodeQueue.pop();
                sum += popNode->val;
                ++count;
                if (popNode->left) nodeQueue.emplace(popNode->left);
                if (popNode->right) nodeQueue.emplace(popNode->right);
            }
            size = nodeQueue.size();
            result.push_back(sum/count);
        }
        return result;
    }
};