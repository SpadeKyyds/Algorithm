/**
 * Middle
 * 
 * 给定一个不重复的整数数组 nums 。 最大二叉树 可以用下面的算法从 nums 递归地构建:

    创建一个根节点，其值为 nums 中的最大值。
    递归地在最大值 左边 的 子数组前缀上 构建左子树。
    递归地在最大值 右边 的 子数组后缀上 构建右子树。
    返回 nums 构建的 最大二叉树 。

     

    示例 1：


    输入：nums = [3,2,1,6,0,5]
    输出：[6,3,5,null,2,0,null,null,1]
    解释：递归调用如下所示：
    - [3,2,1,6,0,5] 中的最大值是 6 ，左边部分是 [3,2,1] ，右边部分是 [0,5] 。
        - [3,2,1] 中的最大值是 3 ，左边部分是 [] ，右边部分是 [2,1] 。
            - 空数组，无子节点。
            - [2,1] 中的最大值是 2 ，左边部分是 [] ，右边部分是 [1] 。
                - 空数组，无子节点。
                - 只有一个元素，所以子节点是一个值为 1 的节点。
        - [0,5] 中的最大值是 5 ，左边部分是 [0] ，右边部分是 [] 。
            - 只有一个元素，所以子节点是一个值为 0 的节点。
            - 空数组，无子节点。
    示例 2：


    输入：nums = [3,2,1]
    输出：[3,null,2,null,1]

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/maximum-binary-tree
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

class Solution {
public:
    void construct(TreeNode** root, vector<int>& nums, int leftIndex, int rightIndex) {
        int i;
        int lChildVal = nums[leftIndex];
        for (i = leftIndex; nums[i] != (*root)->val; ++i) {
            if (nums[i] > lChildVal) lChildVal = nums[i];
        }
        if (lChildVal != (*root)->val) {
            TreeNode* lChild = new TreeNode(lChildVal);
            (*root)->left = lChild;
            construct(&lChild, nums, leftIndex, i - 1);
        }

        int rChildVal = nums[rightIndex];
        for (i = rightIndex; nums[i] != (*root)->val; --i) {
            if (nums[i] > rChildVal) rChildVal = nums[i];
        }
        if (rChildVal != (*root)->val) {
            TreeNode* rChild = new TreeNode(rChildVal);
            (*root)->right = rChild;
            construct(&rChild, nums, i + 1, rightIndex);
        }
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int rootVal = *nums.begin();
        for (auto iter = nums.begin(); iter != nums.end(); ++iter) {
            if (*iter > rootVal) rootVal = *iter;
        }
        TreeNode* root = new TreeNode(rootVal);
        construct(&root, nums, 0, nums.size() - 1);
        return root;
    }
};