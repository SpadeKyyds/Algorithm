/**
 * Middle
 * 
 * 给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。

    有效 二叉搜索树定义如下：

    节点的左子树只包含 小于 当前节点的数。
    节点的右子树只包含 大于 当前节点的数。
    所有左子树和右子树自身必须也是二叉搜索树。
     

    示例 1：


    输入：root = [2,1,3]
    输出：true
    示例 2：


    输入：root = [5,1,4,null,null,3,6]
    输出：false
    解释：根节点的值是 5 ，但是右子节点的值是 4 。

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/validate-binary-search-tree
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
    // 我的版本 并未利用中序遍历递增特性 最好时间复杂度O(logn) 最坏O(nlogn)
    // 后台数据集并未给出空节点的例子
    bool isValidBST(TreeNode* root) {
        TreeNode* minNode; //右子树中值最小的节点
        TreeNode* maxNode; //左子树中值最大的节点
        if (!root->left && !root->right) return true;
        else if (!root->left && root->right) {
            minNode = root->right;
            while (minNode->left != nullptr) minNode = minNode->left;
            return root->val < minNode->val && isValidBST(root->right);
        }
        else if (root->left && !root->right) {
            maxNode = root->left;
            while (maxNode->right != nullptr) maxNode = maxNode->right;
            return root->val > maxNode->val && isValidBST(root->left);
        } else {
            minNode = root->right;
            maxNode = root->left;
            while (minNode->left != nullptr) minNode = minNode->left;
            while (maxNode->right != nullptr) maxNode = maxNode->right;
            return root->val < minNode->val && root->val > maxNode->val && isValidBST(root->left) && isValidBST(root->right);
        }
    }

    // 卡尔的版本 利用了中序遍历一定为递增序列的特性
    // 时间复杂度O(n)
    TreeNode* pre = nullptr;
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        bool left = isValidBST(root->left);
        if (pre == nullptr || root->val > pre->val) pre = root;
        else return false;
        bool right = isValidBST(root->right);
        return left && right;
    }
};