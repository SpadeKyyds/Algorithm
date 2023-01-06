/**
 * Middle
 * 
 * 给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。

    一般来说，删除节点可分为两个步骤：

    首先找到需要删除的节点；
    如果找到了，删除它。
     

    示例 1:



    输入：root = [5,3,6,2,4,null,7], key = 3
    输出：[5,4,6,2,null,null,7]
    解释：给定需要删除的节点值是 3，所以我们首先找到 3 这个节点，然后删除它。
    一个正确的答案是 [5,4,6,2,null,null,7], 如下图所示。
    另一个正确答案是 [5,2,6,null,4,null,7]。


    示例 2:

    输入: root = [5,3,6,2,4,null,7], key = 0
    输出: [5,3,6,2,4,null,7]
    解释: 二叉树不包含值为 0 的节点
    示例 3:

    输入: root = [], key = 0
    输出: []
     

    提示:

    节点数的范围 [0, 104].
    -105 <= Node.val <= 105
    节点值唯一
    root 是合法的二叉搜索树
    -105 <= key <= 105

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/delete-node-in-a-bst
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

// 真的叼！考虑细致 两遍直接写出 运行通过 时间复杂度O(h) (h为树的高度)
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;
        if (root->val == key) {
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            } else {
                TreeNode* pre = root; //pre是temp的前驱节点
                TreeNode* temp = root->right; //temp为要删除的目标节点
                while (temp->left != nullptr) {
                    pre = temp;
                    temp = temp->left;
                }
                root->val = temp->val; // 偷天换日 绝！
                //这里temp一定是pre的左孩子 因为是最左下角的节点
                if (temp != root->right) pre->left = deleteNode(temp, temp->val);
                else pre->right = deleteNode(temp, temp->val);
                return root; //这里要注意 返回的仍然是root 要考虑上一层递归的接收节点
            }
        } else if (key < root->val) root->left = deleteNode(root->left, key);
        else root->right = deleteNode(root->right, key);
        return root;
    }
};