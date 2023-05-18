/**
 * Easy
 * 
 * 给定一个二叉树，找出其最小深度。

    最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

    说明：叶子节点是指没有子节点的节点。

     

    示例 1：


    输入：root = [3,9,20,null,null,15,7]
    输出：2
    示例 2：

    输入：root = [2,null,3,null,4,null,5,null,6]
    输出：5

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/minimum-depth-of-binary-tree
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <queue>
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
    int minDepth(TreeNode* root) {
        queue<TreeNode*> nodeQueue;
        TreeNode* node = root, *popNode;
        int size, count = 0;

        if (node == nullptr) return 0;
        nodeQueue.emplace(node);
        size = nodeQueue.size();
        while (!nodeQueue.empty()) {
            while (size--) {
                popNode = nodeQueue.front();
                nodeQueue.pop();
                // 如果出现了叶子节点 则程序可以直接结束 返回count
                if (!popNode->left && !popNode->right) return ++count;
                if (popNode->left) nodeQueue.emplace(popNode->left);
                if (popNode->right) nodeQueue.emplace(popNode->right);
            }
            size = nodeQueue.size();
            ++count;
        }
        return count;
    }
};