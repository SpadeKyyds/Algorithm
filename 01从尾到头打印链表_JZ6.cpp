#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :     val(x), next(NULL) {}
};

// 个人实现的数组反转版本 O(n)
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> arr;
        while (head != nullptr) {
            arr.push_back(head->val);
            head = head->next;
        }
        reverse(arr.begin(), arr.end());
        return arr;
    }
};

// 栈实现
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        stack<int> st;
        vector<int> res;
        while (head) {
            st.push(head->val);
            head = head->next;
        }
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};

// 递归实现
class Solution {
public:
    void recursion(ListNode* head, vector<int>& res) {
        if (head != nullptr) {
            recursion(head->next, res);
            res.push_back(head->val);
        }
    }

    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        recursion(head, res);
        return res;
    }
};