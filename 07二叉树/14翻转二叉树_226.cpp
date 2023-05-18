/**
 * Easy
 * 
 * 给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。

     

    示例 1：



    输入：root = [4,2,7,1,3,6,9]
    输出：[4,7,2,9,6,3,1]
    示例 2：



    输入：root = [2,1,3]
    输出：[2,3,1]
    示例 3：

    输入：root = []
    输出：[]

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/invert-binary-tree
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

// 递归写法
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root != nullptr) {
            // 我这应该是属于后序遍历的写法
            TreeNode* node = invertTree(root->left);
            root->left = invertTree(root->right);
            root->right = node;
        }
        return root;
    }
};

// 迭代写法
