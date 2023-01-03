/**
 * Easy
 * 
 * 给定二叉搜索树（BST）的根节点 root 和一个整数值 val。

    你需要在 BST 中找到节点值等于 val 的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 null 。

     

    示例 1:



    输入：root = [4,2,7,1,3], val = 2
    输出：[2,1,3]
    示例 2:


    输入：root = [4,2,7,1,3], val = 5
    输出：[]

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/search-in-a-binary-search-tree
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
    // 递归法
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr) return nullptr;
        else if (val < root->val) return searchBST(root->left, val);
        else if (val > root->val) return searchBST(root->right, val);
        else return root;
    }

    // 迭代法 此题也简单
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root != nullptr) {
            if (val < root->val) root = root->left;
            else if (val > root->val) root = root->right;
            else return root;
        }
        return nullptr;
    }
};