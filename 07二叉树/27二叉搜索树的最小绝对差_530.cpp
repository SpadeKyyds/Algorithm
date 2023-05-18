/**
 * Easy
 * 
 * 给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。

    差值是一个正数，其数值等于两值之差的绝对值。

     

    示例 1：


    输入：root = [4,2,6,1,3]
    输出：1
    示例 2：


    输入：root = [1,0,48,null,null,12,49]
    输出：1

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/minimum-absolute-difference-in-bst
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

// 二叉搜索树考虑中序遍历就很简单！
// 这里有一个点：最小差值一定是在中序序列的相邻两节点之间产生 因为中序序列单调递增
class Solution {
private:
    TreeNode* pre = nullptr;
    int result = INT16_MAX;

public:
    void inorderTraverse(TreeNode* root) {
        if (root == nullptr) return;
        inorderTraverse(root->left);
        if (pre != nullptr) result = min(result, root->val - pre->val);
        pre = root;
        inorderTraverse(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        inorderTraverse(root);
        return result;
    }
};