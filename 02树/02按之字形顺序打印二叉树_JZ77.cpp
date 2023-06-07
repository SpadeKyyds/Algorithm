#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(nullptr), right(nullptr) {
	}
};

// 就是在原来统计最大深度的基础上 加上一个判断语句 将结果加入一个数组即可
class Solution {
public:
    vector<vector<int>> Print(TreeNode* pRoot) {
        queue<TreeNode*> q; //辅助队列 实现层序遍历
        vector<vector<int>> res; //结果接收数组
        vector<int> levelVal;
        if (pRoot == nullptr) return {};
        q.push(pRoot);
        int size = q.size();
        int level = 0; //记录树的层次 取余来判断应该向左还是向右遍历
        while (!q.empty()) {
            while (size--) {
                if (q.front()->left != nullptr) q.push(q.front()->left);
                if (q.front()->right != nullptr) q.push(q.front()->right);
                levelVal.push_back(q.front()->val);
                q.pop();
            }
            size = q.size();
            ++level;
            if (level % 2 != 0) res.push_back(levelVal);
            else {
                reverse(levelVal.begin(), levelVal.end());
                res.push_back(levelVal);
            }
            levelVal.clear();
        }
        return res;
    }    
};