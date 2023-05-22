/**
 * 难度：中等
 * 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

     

    示例 1：


    输入：head = [1,2,3,4,5], n = 2
    输出：[1,2,3,5]
    示例 2：

    输入：head = [1], n = 1
    输出：[]
    示例 3：

    输入：head = [1,2], n = 1
    输出：[1]

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/remove-nth-node-from-end-of-list
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur = head;
        ListNode* rear = head;
        ListNode* pre;
        while (n--) rear = rear->next;
        while (rear) {
            rear = rear->next;
            pre = cur;
            cur = cur->next;
        }
        if (cur == head) {
            head = cur->next;
        } else {
            pre->next = cur->next;
        }
        delete cur;
        return head;
    }
};

// 卡尔的带虚拟头结点版本 避免了额外考虑删除头结点的情况 时间复杂度O(n) 空间复杂度O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* slow = dummyHead;
        ListNode* fast = dummyHead;
        ++n; //让slow指向目标节点的前一个节点
        while (n-- && fast) fast = fast->next;
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        head = dummyHead->next;
        delete dummyHead, temp;
        return head;
    }
};