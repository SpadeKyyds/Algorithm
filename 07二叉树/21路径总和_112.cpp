/**
 * Easy
 * 
 * 给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 targetSum 。如果存在，返回 true ；否则，返回 false 。

    叶子节点 是指没有子节点的节点。

     

    示例 1：


    输入：root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
    输出：true
    解释：等于目标和的根节点到叶节点路径如上图所示。
    示例 2：


    输入：root = [1,2,3], targetSum = 5
    输出：false
    解释：树中存在两条根节点到叶子节点的路径：
    (1 --> 2): 和为 3
    (1 --> 3): 和为 4
    不存在 sum = 5 的根节点到叶子节点的路径。
    示例 3：

    输入：root = [], targetSum = 0
    输出：false
    解释：由于树是空的，所以不存在根节点到叶子节点的路径。

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/path-sum
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * Definition for a binary tree node.
*/

#include <iostream>
using namespace std;
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// 秒！自己写出来了！！！
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        // 注意这里是targetSum == root->val 而不是targetSum == 0 因为此时还未从sum中减去叶子节点的值
        if (!root->left && !root->right && targetSum == root->val) return true;
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};

void treeConstruct(TreeNode** root) {
    TreeNode* seven = new TreeNode(7, nullptr, nullptr);
    TreeNode* two = new TreeNode(2, nullptr, nullptr);
    TreeNode* eleven = new TreeNode(11, seven, two);
    TreeNode* fourth = new TreeNode(4, eleven, nullptr);
    TreeNode* one = new TreeNode(1, nullptr, nullptr);
    TreeNode* four = new TreeNode(4, nullptr, one);
    TreeNode* thirteen = new TreeNode(13, nullptr, nullptr);
    TreeNode* eight = new TreeNode(8, thirteen, four);
    TreeNode* five = new TreeNode(5, fourth, eight);

    *root = five;
}

int main() {
    Solution s;
    TreeNode* root;
    treeConstruct(&root);
    cout << s.hasPathSum(root, 22) << endl;
    return 0;
}