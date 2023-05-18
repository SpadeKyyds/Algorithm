/**
 * Easy
 * 
 * 给你一个含重复值的二叉搜索树（BST）的根节点 root ，找出并返回 BST 中的所有 众数（即，出现频率最高的元素）。

    如果树中有不止一个众数，可以按 任意顺序 返回。

    假定 BST 满足如下定义：

    结点左子树中所含节点的值 小于等于 当前节点的值
    结点右子树中所含节点的值 大于等于 当前节点的值
    左子树和右子树都是二叉搜索树
     

    示例 1：


    输入：root = [1,null,2,2]
    输出：[2]
    示例 2：

    输入：root = [0]
    输出：[0]

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/find-mode-in-binary-search-tree
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

// 个人实现的版本 时间复杂度O(n) 空间复杂度O(n) 
// 相比于卡尔的不是很好理解 但是比卡尔的优化些
class Solution {
private:
    TreeNode* pre = nullptr;
    int count = 0;
    int maxCount = 0;
    vector<int> result;

public:
    void inorderTraverse(TreeNode* root) {
        if (!root) return;
        inorderTraverse(root->left);
        // 这里有一定的优化 主要在于遍历到不同值时才去操作结果数组
        if (pre != nullptr && pre->val != root->val) {
            if (count > maxCount) {
                maxCount = count;
                result.clear();
                result.push_back(pre->val);
            }
            // 这里不可直接用两个if 因为maxCount的值在前面一个if里面会改变未count的值
            else if (count == maxCount) result.push_back(pre->val);
            else {}
            count = 0;
        }
        pre = root;
        ++count;
        inorderTraverse(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        inorderTraverse(root);
        // 这里还进行一次判断就是处理最后一个节点的特殊情况
        if (count > maxCount) {
            result.clear();
            result.push_back(pre->val);
        }
        else if (count == maxCount) result.push_back(pre->val);
        else {}
        return result;
    }
};