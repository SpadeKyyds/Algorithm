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
    vector<string> binaryTreePaths(TreeNode* root) {

    }
};