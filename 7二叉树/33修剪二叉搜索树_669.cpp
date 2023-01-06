/**
 * Middle
 * 
 * 给你二叉搜索树的根节点 root ，同时给定最小边界low 和最大边界 high。通过修剪二叉搜索树，使得所有节点的值在[low, high]中。修剪树 不应该 改变保留在树中的元素的相对结构 (即，如果没有被移除，原有的父代子代关系都应当保留)。 可以证明，存在 唯一的答案 。

    所以结果应当返回修剪好的二叉搜索树的新的根节点。注意，根节点可能会根据给定的边界发生改变。

     

    示例 1：


    输入：root = [1,0,2], low = 1, high = 2
    输出：[1,null,2]
    示例 2：


    输入：root = [3,0,4,null,2,null,null,1], low = 1, high = 3
    输出：[3,2,null,1]
     

    提示：

    树中节点数在范围 [1, 104] 内
    0 <= Node.val <= 104
    树中每个节点的值都是 唯一 的
    题目数据保证输入是一棵有效的二叉搜索树
    0 <= low <= high <= 104

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/trim-a-binary-search-tree
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

// 这题不是很理解 可以说很难 而且容易陷入到上一题的逻辑里面去
// 做题切忌这种 应该是由题意发散到相同的解法 而不是由已有的现成解法 往题意去凑
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == nullptr) return nullptr;
        if (root->val < low) return trimBST(root->right, low, high);
        else if (root->val > high) return trimBST(root->left, low, high);
        else {
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
        }
        return root;
    }
};