/**
 * Easy
 * 
 * 给你二叉树的根节点 root ，返回它节点值的 前序 遍历。

     

    示例 1：


    输入：root = [1,null,2,3]
    输出：[1,2,3]
    示例 2：

    输入：root = []
    输出：[]
    示例 3：

    输入：root = [1]
    输出：[1]
    示例 4：


    输入：root = [1,2]
    输出：[1,2]
    示例 5：


    输入：root = [1,null,2]
    输出：[1,2]

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/binary-tree-preorder-traversal
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


/**
 * 递归三部曲：
 * 1.确定递归函数的参数和返回值：
 *   确定哪些参数是递归过程中需要处理的，那么就在递归函数里加上这个参数，
 *   并且还要明确每次递归的返回值是什么，进而确定递归函数的返回值类型
 * 
 * 2.确定终止条件：
 *   操作系统使用栈结构来存储每一层递归信息，如果递归没有终止，则内存栈会溢出
 * 
 * 3.确定单层递归的逻辑：
 *   确定每一层递归需要处理的信息，这里会重复调用自己来实现递归过程
*/


/****************************************************************************
 * emplace和push的区别 
 * emplace直接传入参数即可，容器内部构造对象
 * push需要构造一个局部临时对象 才可以加入到容器中
*****************************************************************************/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// recursion
// 时间复杂度O(n) 空间复杂度O(n)
class Solution {
private:
    vector<int> result;

public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (root != nullptr) {
            result.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
        return result;
    }
};

// iteration
// 时间复杂度O(n) 空间复杂度O(n)
class Solution1 {
private:
    vector<int> result;
    stack<TreeNode*> nodeStack;

public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr) return result;
        TreeNode* node = root;
        while (!nodeStack.empty() || node != nullptr) {
            while (node != nullptr) {
                result.emplace_back(node->val);
                nodeStack.emplace(node);
                node = node->left;
            }
            node = nodeStack.top();
            nodeStack.pop();
            node = node->right;
        }
        return result;
    }
};