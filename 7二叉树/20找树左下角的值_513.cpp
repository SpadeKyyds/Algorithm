/**
 * Middle
 * 
 * 给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。

    假设二叉树中至少有一个节点。

     

    示例 1:



    输入: root = [2,1,3]
    输出: 1
    示例 2:



    输入: [1,2,3,4,null,5,6,null,null,7]
    输出: 7

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/find-bottom-left-tree-value
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * Definition for a binary tree node.
*/

#include <iostream>
using namespace std;
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 个人思考的层次遍历方法 此题更好理解
class Solution {
private:
    queue<TreeNode*> nodeQueue;
    int bottomLeftValue, size;
    TreeNode* node;

public:
    int findBottomLeftValue(TreeNode* root) {
        // 这里考虑一下空树的特殊情况 返回-1 力扣后台并没有这样的数据
        if (root == nullptr) return -1;
        nodeQueue.emplace(root);
        size = nodeQueue.size();
        while (!nodeQueue.empty()) {
            bottomLeftValue = nodeQueue.front()->val;
            while (size--) {
                node = nodeQueue.front();
                nodeQueue.pop();
                if (node->left) nodeQueue.emplace(node->left);
                if (node->right) nodeQueue.emplace(node->right);
            }
            size = nodeQueue.size();
        }
        return bottomLeftValue;
    }
};

// 卡尔的深度递归遍历 含回溯的思想
class Solution {
private:
    int result, maxDepth = INT16_MIN;
public:
    void findValue(TreeNode* root, int depth) {
        // 终止条件
        if (!root->left && !root->right && depth > maxDepth) {
            maxDepth = depth;
            result = root->val;
        }
        // 单层递归逻辑
        if (root->left) findValue(root->left, depth + 1); // 这里隐藏着回溯
        if (root->right) findValue(root->right, depth + 1);
    }

    int findBottomLeftValue(TreeNode* root) {
        findValue(root, 1);
        return result;
    }
};