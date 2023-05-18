/**
 * Easy
 * 
 * 给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。

     

    示例 1：


    输入：root = [1,null,2,3]
    输出：[1,3,2]
    示例 2：

    输入：root = []
    输出：[]
    示例 3：

    输入：root = [1]
    输出：[1]

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/binary-tree-inorder-traversal
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// recursion
class Solution {
private:
    vector<int> result;

public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (root != nullptr) {
            inorderTraversal(root->left);
            result.push_back(root->val);
            inorderTraversal(root->right);
        }
        return result;
    }
};

// iteration
// 时间复杂度O(n) 空间复杂度O(n)
class Solution {
private:
    vector<int> result;
    stack<TreeNode*> nodeStack;

public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) return result;
        TreeNode* node = root;
        while (!nodeStack.empty() || node != nullptr) {
            while (node != nullptr) {
                nodeStack.emplace(node);
                node = node->left;
            }
            node = nodeStack.top();
            nodeStack.pop();
            result.emplace_back(node->val);
            node = node->right;
        }
        return result;
    }
};