/**
 * Easy
 * 
 * 给定一个二叉树，找出其最大深度。

    二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

    说明: 叶子节点是指没有子节点的节点。

    示例：
    给定二叉树 [3,9,20,null,null,15,7]，

        3
    / \
    9  20
        /  \
    15   7
    返回它的最大深度 3 。

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/maximum-depth-of-binary-tree
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * 高度：节点到叶子节点的距离 后序遍历
 * 深度：节点到根节点的距离 先序遍历
 * 求出高度就可得到深度？因为根节点的高度就是二叉树的最大深度
 * 很多题解都是使用后序遍历求高度 进而得到深度信息
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
    int maxDepth(TreeNode* root) {
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
                if (popNode->left) nodeQueue.emplace(popNode->left);
                if (popNode->right) nodeQueue.emplace(popNode->right);
            }
            size = nodeQueue.size();
            ++count;
        }
        return count;
    }
};