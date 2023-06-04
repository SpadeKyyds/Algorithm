#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        if (pHead1 == nullptr) return pHead2; //空表判断
        else if (pHead2 == nullptr) return pHead1;
        else {
            // 碰见这种需要判断哪个为表头的情况 考虑虚拟头节点
            ListNode* dummyHead = new ListNode(0);
            ListNode* cur = dummyHead;
            // 在两表均不为空的情况下 比较节点的值 进行指针移动
            while (pHead1 && pHead2) {
                if (pHead1->val <= pHead2->val) {
                    cur->next = pHead1;
                    pHead1 = pHead1->next;
                } else {
                    cur->next = pHead2;
                    pHead2 = pHead2->next;
                }
                cur = cur->next;
            }
            // 最后如果有表未完 则直接将剩余的表部分接入到cur指针后面即可
            if (pHead1 != nullptr) {
                cur->next = pHead1;
            } else {
                cur->next = pHead2;
            }
            ListNode* head = dummyHead->next;
            delete dummyHead;
            return head;
        }
    }
};