/**
 * Middle
 * 
 * 给定一个 N 叉树，返回其节点值的层序遍历。（即从左到右，逐层遍历）。

    树的序列化输入是用层序遍历，每组子节点都由 null 值分隔（参见示例）。

     

    示例 1：



    输入：root = [1,null,3,2,4,null,5,6]
    输出：[[1],[3,2,4],[5,6]]
    示例 2：



    输入：root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
    输出：[[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/n-ary-tree-level-order-traversal
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        vector<int> levelNodeVector;
        queue<Node*> nodeQueue;
        Node* node = root, *popNode;
        int size;

        if (node == nullptr) return result;
        nodeQueue.emplace(node);
        size = nodeQueue.size(); //using size to control node pop numbers on every level
        while (!nodeQueue.empty()) {
            while (size--) {
                popNode = nodeQueue.front();
                nodeQueue.pop();
                levelNodeVector.push_back(popNode->val);
                for (auto iter = popNode->children.begin(); iter != popNode->children.end(); ++iter) {
                    nodeQueue.emplace(*iter);
                }
            }
            size = nodeQueue.size();
            result.push_back(levelNodeVector);
            levelNodeVector.clear();
        }
        return result;     
    }
};