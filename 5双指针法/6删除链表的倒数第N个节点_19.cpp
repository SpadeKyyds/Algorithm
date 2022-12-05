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
     

    提示：

    链表中结点的数目为 sz
    1 <= sz <= 30
    0 <= Node.val <= 100
    1 <= n <= sz

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/remove-nth-node-from-end-of-list
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 此种错位的快慢指针相对于同位（开始时刻）的快慢指针 更加简洁直观一点
// 时间复杂度仍然为O(n) 空间复杂度仍然为O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0, head);
        ListNode *slow = dummyHead, *fast = head;
        while (n--) fast = fast->next;
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* temp = slow->next;
        slow->next = temp->next;
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};