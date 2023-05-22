/**
 * Easy
 * 
 * 给你一棵二叉树的根节点 root ，返回其节点值的 后序遍历 。

     

    示例 1：


    输入：root = [1,null,2,3]
    输出：[3,2,1]
    示例 2：

    输入：root = []
    输出：[]
    示例 3：

    输入：root = [1]
    输出：[1]

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/binary-tree-postorder-traversal
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <stack>
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

// recursion
class Solution {
private:
    vector<int> result;

public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (root != nullptr) {
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            result.push_back(root->val);
        }
        return result;
    }
};

// iteration
// 时间复杂度O(n) 空间复杂度O(n)


// // 此方法修改前序遍历的顺序得到 玩具解法 非真正的后序遍历
// class Solution {
// private:
//     vector<int> result;
//     stack<TreeNode*> nodeStack;

// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//         if (root == nullptr) return result;
//         TreeNode* node = root;
//         while (!nodeStack.empty() || node != nullptr) {
//             while (node != nullptr) {
//                 result.emplace_back(node->val);
//                 nodeStack.emplace(node);
//                 node = node->right;
//             }
//             node = nodeStack.top();
//             nodeStack.pop();
//             node = node->left;
//         }
//         reverse(result.begin(), result.end());     
//         return result;
//     }
// };

// 真正的后序非递归遍历
// class Solution1 {
// private:
//     vector<int> result;
//     stack<pair<TreeNode*, bool>> pairNodeStack;

// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//         if (root == nullptr) return result;
//         pair<TreeNode*, bool> pairNode;
//         TreeNode* node = root;
//         while (!pairNodeStack.empty() || node != nullptr) {
//             while (node != nullptr) {
//                 pairNodeStack.emplace(node, false);
//                 node = node->left;
//             }
//             pairNode = pairNodeStack.top();
//             node = pairNode.first;
//             if (pairNode.second == false) {
//                 pairNodeStack.top().second = true;
//                 node = node->right;
//             } else {
//                 while (pairNode.second == true) {
//                     result.push_back(node->val);
//                     pairNodeStack.pop();
//                     if (!pairNodeStack.empty()) {
//                         pairNode = pairNodeStack.top();
//                         node = pairNode.first;
//                     } else {
//                         cout << node << endl;
//                         node = nullptr;
//                         break;
//                     }
//                 }
//                 if (!pairNodeStack.empty()) {
//                     pairNodeStack.top().second = true;
//                     node = node->right;
//                 }
//             }
//         }
//         return result;
//     }
// };

// 简化版本 同上面Solution1
class Solution {
private:
    vector<int> result;
    stack<pair<TreeNode*, bool>> nodeStack;

public:
    vector<int> postorderTraversal(TreeNode* root) {
        // 如果是空树，直接返回空数组
        if (root == nullptr) return result;
        // 键值对栈
        pair<TreeNode*, bool> node;
        node.first = root;
        while (!nodeStack.empty() || node.first != nullptr) {
            while (node.first != nullptr) {
                // 将左孩子压入栈 直至左孩子为空 flag置false
                nodeStack.emplace(node.first, false);
                node.first = node.first->left;
            }
            // 左孩子访问完 访问栈顶节点
            node = nodeStack.top();
            // flag为false 表示访问此根节点时 还未访问右孩子节点
            if (node.second == false) {
                nodeStack.top().second = true;
                node.first = node.first->right;
            } else {
                // flag为true表示此时已经访问过了右孩子节点 可以将根节点压入vector了
                while (node.second == true) {
                    result.push_back(node.first->val);
                    nodeStack.pop();
                    // 如果此时栈非空 继续遍历栈顶节点 栈顶节点的右孩子节点未访问过则会跳出循环
                    if (!nodeStack.empty()) node = nodeStack.top();
                    // 如果此时栈空，则表示已经遍历结束，可直接返回vector数组
                    // 因为只有在左右孩子节点都访问完才会访问根节点 进而根节点才会出栈
                    else return result;
                }
                // 将根节点的标志位置true 访问右子树
                nodeStack.top().second = true;
                node.first = node.first->right;
            }
        }
        return result;
    }
};

void treeConstruct(TreeNode** root) {
    TreeNode* three = new TreeNode(3);
    TreeNode* two = new TreeNode(2, three, nullptr);
    TreeNode* one = new TreeNode(1, nullptr, two);
    *root = one;
}

void printVector(vector<int> result) {
    for (auto iter = result.begin(); iter != result.end(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;
}

int main() {
    Solution s;
    TreeNode* root;
    treeConstruct(&root);

    vector<int> result;
    result = s.postorderTraversal(root);
    printVector(result);
    return 0;
}