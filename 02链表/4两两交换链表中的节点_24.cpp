/**
 * 难度：中等
 * 给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。

     

    示例 1：


    输入：head = [1,2,3,4]
    输出：[2,1,4,3]
    示例 2：

    输入：head = []
    输出：[]
    示例 3：

    输入：head = [1]
    输出：[1]

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/swap-nodes-in-pairs
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

// 真的牛皮！历经一天时间，自己想出来了！鼓励一波！
// 时间复杂度O(n) 空间复杂度O(1)
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head; //这是空表和一个节点时候情况，无需任何操作，直接返回头节点即可
        } else {
            // 如果表中至少有两个节点 则头节点一定为第二个节点 提前存下来
            ListNode* returnHead = head->next;
            ListNode* pre = head;
            //这里千万只能用pre&&pre->next 而不能用cur = pre->next，如果pre为空就会出错
            while (pre && pre->next) {
                ListNode* cur = pre->next;
                ListNode* temp = cur->next;
                cur->next = pre;
                if (!temp || !temp->next) {
                    // 如果没有第三个节点 或没有第四个节点 则第二次循环不用进行
                    // 或者进行了也保证了第一个节点指针指向了正确位置
                    pre->next = temp;
                } else {
                    // 这行代码是精髓，如果后面还有两个节点，第一个节点pre直接指向第四个节点
                    pre->next = temp->next;
                }
                pre = temp;
            }
            return returnHead;
        }
    }
};

// 卡尔解法，添加了虚拟头节点 更为简洁精辟 记忆版本
// 时间复杂度O(n) 空间复杂度O(1)
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* cur = dummyHead;
        while (cur->next && cur->next->next) {
            ListNode* temp0 = cur->next;
            cur->next = temp0->next;
            ListNode* temp1 = cur->next->next;
            cur->next->next = temp0;
            temp0->next = temp1;
            cur = temp0;
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};