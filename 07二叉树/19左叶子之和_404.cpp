/**
 * Easy
 * 
 * 给定二叉树的根节点 root ，返回所有左叶子之和。

     

    示例 1：



    输入: root = [3,9,20,null,null,15,7] 
    输出: 24 
    解释: 在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
    示例 2:

    输入: root = [1]
    输出: 0

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/sum-of-left-leaves
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
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
    void sumOfNodes(int& sum, TreeNode* root) {
        // 这里要带上root->right != nullptr的情况 因为右子树也可以有左叶子节点
        if (root != nullptr && (root->left != nullptr || root->right != nullptr)) {
            if (root->left != nullptr && !root->left->left && !root->left->right) sum += root->left->val;
            sumOfNodes(sum, root->left);
            sumOfNodes(sum, root->right);
        }
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        sumOfNodes(sum, root);
        return sum;
    }
};