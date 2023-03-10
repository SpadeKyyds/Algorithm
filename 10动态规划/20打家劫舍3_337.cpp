/**
 * 小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为 root 。

    除了 root 之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果 两个直接相连的房子在同一天晚上被打劫 ，房屋将自动报警。

    给定二叉树的 root 。返回 在不触动警报的情况下 ，小偷能够盗取的最高金额 。

     

    示例 1:



    输入: root = [3,2,3,null,3,null,1]
    输出: 7 
    解释: 小偷一晚能够盗取的最高金额 3 + 3 + 1 = 7
    示例 2:



    输入: root = [3,4,5,1,3,null,1]
    输出: 9
    解释: 小偷一晚能够盗取的最高金额 4 + 5 = 9
     

    提示：

    树的节点数在 [1, 104] 范围内
    0 <= Node.val <= 104

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/house-robber-iii
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 树形DP 时间复杂度O(n):每个节点只遍历一次  空间复杂度O(logn):递归系统栈空间
// dp数组就是一个二维的数组 表示当前节点偷与不偷所能得到的最大金币
// 须采取后序遍历 当前节点偷与不偷所带来的金币数参考叶子节点的偷与不偷
// 递归返回的过程中带来了下层节点偷与不偷的最大收益 一直返回到根节点 体现了递归的精髓
// 本题作为树形DP的第一道题目 没有做出来 树的遍历掌握还是不够
class Solution {
public:
    vector<int> robTree(TreeNode* current) {
        if (current == nullptr) return {0, 0};
        vector<int> left = robTree(current->left);
        vector<int> right = robTree(current->right);
        int robVal = current->val + left[0] + right[0];
        int not_robVal = max(left[0], left[1]) + max(right[0], right[1]);
        return {not_robVal, robVal};
    }

    int rob(TreeNode* root) {
        vector<int> result;
        result = robTree(root);
        return max(result[0], result[1]);
    }
};