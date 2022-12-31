/**
 * Easy
 * 
 * 给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。

    叶子节点 是指没有子节点的节点。

     
    示例 1：


    输入：root = [1,2,3,null,5]
    输出：["1->2->5","1->3"]
    示例 2：

    输入：root = [1]
    输出：["1"]

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/binary-tree-paths
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
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
    void pathConstruct(TreeNode* root, string path, vector<string>& paths) {
        if (root != nullptr) {
            path += to_string(root->val);
            if (!root->left && !root->right) {
                paths.push_back(path);
            } else {
                path += "->";
                // 这里path不需要以引用方式传入 每一级递归的path都不相同 不停地拷贝复制
                pathConstruct(root->left, path, paths);
                pathConstruct(root->right, path, paths);
            }
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        pathConstruct(root, "", paths);
        return paths;
    }
};