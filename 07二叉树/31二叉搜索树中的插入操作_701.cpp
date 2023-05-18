/**
 * Middle
 * 
 * 给定二叉搜索树（BST）的根节点 root 和要插入树中的值 value ，将值插入二叉搜索树。 返回插入后二叉搜索树的根节点。 输入数据 保证 ，新值和原始二叉搜索树中的任意节点值都不同。

    注意，可能存在多种有效的插入方式，只要树在插入后仍保持为二叉搜索树即可。 你可以返回 任意有效的结果 。

     

    示例 1：


    输入：root = [4,2,7,1,3], val = 5
    输出：[4,2,7,1,3,5]
    解释：另一个满足题目要求可以通过的树是：

    示例 2：

    输入：root = [40,20,60,10,30,50,70], val = 25
    输出：[40,20,60,10,30,50,70,null,null,25]
    示例 3：

    输入：root = [4,2,7,1,3,null,null,null,null,null,null], val = 5
    输出：[4,2,7,1,3,5]

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/insert-into-a-binary-search-tree
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

// 递归法个人实现版本
    void insertNode(TreeNode* node, int val) {
        if (node->val > val && node->left == nullptr) {
            node->left =  new TreeNode(val);
            return;
        }
        if (node->val < val && node->right == nullptr) {
            node->right = new TreeNode(val);
            return;
        }
        if (node->val > val) insertNode(node->left, val);
        else insertNode(node->right, val);
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) root = new TreeNode(val);
        else insertNode(root, val);
        return root;
    }

// 迭代法个人实现版本
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) root = new TreeNode(val);
        else {
            TreeNode* pre = root, *node = root;
            while (node != nullptr) {
                pre = node;
                if (node->val > val) node = node->left;
                else node = node->right;
            }
            if (pre->val > val) pre->left = new TreeNode(val);
            else pre->right = new TreeNode(val);
        }
        return root;
    }

// 卡尔的递归法 代码精简版本
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) return new TreeNode(val);
        else if (val < root->val) root->left = insertIntoBST(root->left, val);
        else root->right = insertIntoBST(root->right, val);
        return root;
    }
};