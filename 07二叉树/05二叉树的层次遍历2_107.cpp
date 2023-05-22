/**
 * Middle
 * 
 * 给你二叉树的根节点 root ，返回其节点值 自底向上的层序遍历 。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

     

    示例 1：


    输入：root = [3,9,20,null,null,15,7]
    输出：[[15,7],[9,20],[3]]
    示例 2：

    输入：root = [1]
    输出：[[1]]
    示例 3：

    输入：root = []
    输出：[]

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/binary-tree-level-order-traversal-ii
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        vector<int> levelNodeVector;
        queue<TreeNode*> nodeQueue;
        TreeNode* node = root, *popNode;
        int size;

        if (node == nullptr) return result;
        nodeQueue.emplace(node);
        size = nodeQueue.size(); //using size to control node pop numbers on every level
        while (!nodeQueue.empty()) {
            while (size--) {
                popNode = nodeQueue.front();
                nodeQueue.pop();
                levelNodeVector.push_back(popNode->val);
                if (popNode->left) nodeQueue.emplace(popNode->left);
                if (popNode->right) nodeQueue.emplace(popNode->right);
            }
            size = nodeQueue.size();
            result.push_back(levelNodeVector);
            levelNodeVector.clear();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};