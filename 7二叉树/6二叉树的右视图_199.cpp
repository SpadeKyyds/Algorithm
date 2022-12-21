/**
 * Middle
 * 
 * 给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

     

    示例 1:



    输入: [1,2,3,null,5,null,4]
    输出: [1,3,4]
    示例 2:

    输入: [1,null,3]
    输出: [1,3]
    示例 3:

    输入: []
    输出: []

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/binary-tree-right-side-view
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
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
                // 只压入最后一个数 减小开销
                if (size == 0) levelNodeVector.push_back(popNode->val);
                if (popNode->left) nodeQueue.emplace(popNode->left);
                if (popNode->right) nodeQueue.emplace(popNode->right);
            }
            size = nodeQueue.size();
            result.push_back(*levelNodeVector.begin());
            levelNodeVector.clear();
        }
        return result;
    }
};