/**
 * Easy
 * 
 * 给你一个二叉树的根节点 root ， 检查它是否轴对称。

     

    示例 1：


    输入：root = [1,2,2,3,4,4,3]
    输出：true
    示例 2：


    输入：root = [1,2,2,null,3,null,3]
    输出：false

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/symmetric-tree
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
    bool compareNodes(TreeNode* lNode, TreeNode* rNode) {
        if (lNode == nullptr && rNode == nullptr) return true;
        else if (lNode == nullptr && rNode != nullptr) return false;
        else if (lNode != nullptr && rNode == nullptr) return false;
        else if (lNode->val != rNode->val) return false;
        else {
            // 注意这里只能有一个return值 否则出错 二者取逻辑与
            return compareNodes(lNode->left, rNode->right) && compareNodes(lNode->right, rNode->left);
        }
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return compareNodes(root->left, root->right);
    }
};