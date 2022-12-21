/**
 * Middle
 * 
 * 给定一棵二叉树的根节点 root ，请找出该二叉树中每一层的最大值。

     

    示例1：



    输入: root = [1,3,2,5,3,null,9]
    输出: [1,3,9]
    示例2：

    输入: root = [1,2,3]
    输出: [1,3]

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/find-largest-value-in-each-tree-row
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> nodeQueue;
        TreeNode* node = root, *popNode;
        int size, maxValue;

        if (node == nullptr) return result;
        nodeQueue.emplace(node);
        size = nodeQueue.size(); //using size to control node pop numbers on every level
        while (!nodeQueue.empty()) {
            maxValue = nodeQueue.front()->val;
            while (size--) {
                popNode = nodeQueue.front();
                nodeQueue.pop();
                if (popNode->val > maxValue) maxValue = popNode->val;
                if (popNode->left) nodeQueue.emplace(popNode->left);
                if (popNode->right) nodeQueue.emplace(popNode->right);
            }
            size = nodeQueue.size();
            result.push_back(maxValue);
        }
        return result;
    }
};