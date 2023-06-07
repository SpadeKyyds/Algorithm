#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(nullptr), right(nullptr) {
	}
};

// 当一个大的问题可以分解成许多相同的小问题就考虑使用递归来解决
// 本题可分解为：当前树的深度等于左右子树的最大深度+1
class Solution {
public:
    int TreeDepth(TreeNode* pRoot) {
        if (pRoot == nullptr) return 0;
        return max({TreeDepth(pRoot->left), TreeDepth(pRoot->right)}) + 1;
    }
};

// 法2 层序遍历
class Solution {
public:
    int TreeDepth(TreeNode* pRoot) {
        queue<TreeNode*> q;
        if (pRoot == nullptr) return 0;
        q.push(pRoot);
        int level = 0;
        int size = q.size();
        while (!q.empty()) {
            while (size--) {
                if (q.front()->left != nullptr) q.push(q.front()->left);
                if (q.front()->right != nullptr) q.push(q.front()->right);
                q.pop();
            }
            size = q.size();
            ++level;
        }
        return level;
    }
};