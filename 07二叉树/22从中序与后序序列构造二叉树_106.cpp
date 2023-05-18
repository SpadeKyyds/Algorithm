/**
 * Middle
 * 
 * 给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。

     

    示例 1:


    输入：inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
    输出：[3,9,20,null,null,15,7]
    示例 2:

    输入：inorder = [-1], postorder = [-1]
    输出：[-1]

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * Definition for a binary tree node.
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

// 通过自己的努力写出来了！！！
class Solution {
public:
    void rebuild(TreeNode** root, vector<int>& inorder, int leftIndex, int rightIndex, unordered_map<int, int>& map) {
        int i;
        int leftNodeValue = inorder[leftIndex];
        for (i = leftIndex; inorder[i] != (*root)->val; ++i) {
            if (map.find(inorder[i])->second > map.find(leftNodeValue)->second) leftNodeValue = inorder[i];
        }
        // 递归终止的条件其实隐藏在这里 建立在题意所有值均不同的基础上 如果无子树了则不会进入if语句 空执行语句 从而返回上一级递归
        if (leftNodeValue != (*root)->val) {
            TreeNode*  leftChild = new TreeNode(leftNodeValue);
            (*root)->left = leftChild;
            rebuild(&leftChild, inorder, leftIndex, i - 1, map);
        }
        
        // 右子树细节使用倒序 避免了取到空索引的情况
        int rightNodeValue = inorder[rightIndex];
        for (i = rightIndex; inorder[i] != (*root)->val; --i) {
            if (map.find(inorder[i])->second > map.find(rightNodeValue)->second) rightNodeValue = inorder[i];
        }
        if (rightNodeValue != (*root)->val) {
            TreeNode* rightChild = new TreeNode(rightNodeValue);
            (*root)->right = rightChild;
            rebuild(&rightChild, inorder, i + 1, rightIndex, map);
        }
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root = new TreeNode(*(postorder.end() - 1));
        unordered_map<int, int> map;
        int i = 0;
        for (auto iter = postorder.begin(); iter != postorder.end(); ++iter, ++i) {
            map.insert({*iter, i});
        }
        rebuild(&root, inorder, 0, inorder.size() -1, map);
        return root;
    }
};