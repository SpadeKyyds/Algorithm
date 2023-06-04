#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* p) : val(x), next(p) {}
};

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        ListNode* fast = pHead;
        ListNode* slow = pHead;
        if (slow != nullptr && fast->next != nullptr) {
            do {
                slow = slow->next;
                fast = fast->next->next;
            }while (slow != nullptr && fast != nullptr && fast->next != nullptr && slow != fast);
            if (slow == fast && slow != nullptr) {
                fast = pHead;
                while (fast != slow) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return fast;
            }
        }
        return nullptr;
    }
};

void createList(ListNode **head) {
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n3;

    *head = n1;
}

void createList2(ListNode **head) {
    ListNode* n1 = new ListNode(1);
    *head = n1;
}

int main() {
    ListNode* head;
    createList(&head);
    cout << Solution().EntryNodeOfLoop(head)->val << endl;
    return 0;
}