/**
 * Middle
 * 
 * 给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。

    完全二叉树 的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~ 2h 个节点。

     

    示例 1：


    输入：root = [1,2,3,4,5,6]
    输出：6
    示例 2：

    输入：root = []
    输出：0
    示例 3：

    输入：root = [1]
    输出：1

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/count-complete-tree-nodes
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

// 充分利用了完全二叉树的特点 借鉴
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        int leftDepth = 0, rightDepth = 0;
        while (left) {
            ++leftDepth;
            left = left->left;
        }
        while (right) {
            ++rightDepth;
            right = right->right;
        }
        if (leftDepth == rightDepth) return (2 << leftDepth) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};