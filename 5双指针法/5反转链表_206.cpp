/**
 * 难度：简单
 * 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
     

    示例 1：


    输入：head = [1,2,3,4,5]
    输出：[5,4,3,2,1]
    示例 2：


    输入：head = [1,2]
    输出：[2,1]
    示例 3：

    输入：head = []
    输出：[]

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/reverse-linked-list
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

// 按照自己的写法来 一昧追求别人的简洁写法 很难转变成自己的东西
// 虽然多使用了一些内存空间 但总的时间复杂度仍然为O(n) 空间复杂度为O(1) 足矣
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* dummyHead = new ListNode(0, head);
        if (head) {
            ListNode* p = head->next;
            head->next = nullptr;
            while (p) {
                ListNode* temp = p->next;
                p->next = dummyHead->next;
                dummyHead->next = p;
                p = temp;
            }
        }
        ListNode* ptr = dummyHead->next;
        delete dummyHead;
        return ptr;
    }
};