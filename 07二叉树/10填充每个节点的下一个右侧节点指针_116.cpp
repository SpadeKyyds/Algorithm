/**
 * Middle
 * 
 * 给定一个 完美二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：

    struct Node {
    int val;
    Node *left;
    Node *right;
    Node *next;
    }
    填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

    初始状态下，所有 next 指针都被设置为 NULL。

     

    示例 1：



    输入：root = [1,2,3,4,5,6,7]
    输出：[1,#,2,3,#,4,5,6,7,#]
    解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。序列化的输出按层序遍历排列，同一层节点由 next 指针连接，'#' 标志着每一层的结束。
    示例 2:

    输入：root = []
    输出：[]
     

    提示：

    树中节点的数量在 [0, 212 - 1] 范围内
    -1000 <= node.val <= 1000
     

    进阶：

    你只能使用常量级额外空间。
    使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/populating-next-right-pointers-in-each-node
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> nodeQueue;
        Node* node = root, *popNode;
        int size;

        if (node == nullptr) return nullptr;
        nodeQueue.emplace(node);
        size = nodeQueue.size(); 
        while (!nodeQueue.empty()) {
            while (size--) {
                popNode = nodeQueue.front();
                nodeQueue.pop();
                if (size != 0) popNode->next = nodeQueue.front();
                else popNode->next = nullptr;
                // 虽然是完美二叉树 但是这个左右孩子判空还是不能删除 若删除会入队空指针
                if (popNode->left) nodeQueue.emplace(popNode->left);
                if (popNode->right) nodeQueue.emplace(popNode->right);
            }
            size = nodeQueue.size();
        }
        return root;
    }
};

void nodeConstruct(Node** root) {
    Node* seven = new Node(7, nullptr, nullptr, nullptr);
    Node* six = new Node(6, nullptr, nullptr, nullptr);
    Node* five = new Node(5, nullptr, nullptr, nullptr);
    Node* four = new Node(4, nullptr, nullptr, nullptr);
    Node* three = new Node(3, six, seven, nullptr);
    Node* two = new Node(2, four, five, nullptr);
    Node* one = new Node(1, two, three, nullptr);
    *root = one;
}

int main() {
    Node* root;
    nodeConstruct(&root);
    Solution s;
    s.connect(root);
    return 0;
}