#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 最简洁的代码表达 没有之一
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
		if (pHead1 == nullptr || pHead2 == nullptr) return nullptr;
        ListNode* p1 = pHead1;
        ListNode* p2 = pHead2;
        while (p1 != p2) {
            // 最后两者同时为空 判断while条件不满足后也可直接返回p1
			p1 = p1 ? p1->next : pHead2;
			p2 = p2 ? p2->next : pHead1;
        }
        return p1;        
    }
};