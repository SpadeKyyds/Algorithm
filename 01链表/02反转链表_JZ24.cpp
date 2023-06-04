#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* ptr) : val(x), next(ptr) {}
};

// 用了三个指针 写的挺复杂的
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
		if (pHead == nullptr || pHead->next == nullptr) return pHead;
		ListNode* pre = pHead;
		ListNode* cur = pHead->next;
		ListNode* nex = cur->next;
		pre->next = nullptr;
		cur->next = pre;
		while (nex != nullptr) {
			pre = cur;
			cur = nex;
			nex = nex->next;
			cur->next = pre;
		}
		return cur;
    }
};

// 优化的迭代版本 仅仅设置两个指针 第三个节点指针使用temo代替即可
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
		ListNode* pre = nullptr;
		ListNode* cur = pHead;
		while (cur != nullptr) {
			ListNode* temp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = temp;
		}
		return pre;
    }
};