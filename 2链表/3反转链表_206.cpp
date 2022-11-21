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

// 自主一遍完成 用时两小时 分析透彻 牛逼
// 只需画出空表 一个节点 两个节点 三个节点 三种情况的链表图即可完成分析
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* pre = dummyHead; //前驱指针
        ListNode* cur = pre->next; //当前判断的指针
        ListNode* rear; //尾后指针
        while (cur) {
            rear = cur->next;
            cur->next = pre;
            if (cur->next == dummyHead) {
                cur->next = nullptr;
            }
            pre = cur; //这里一定不能用pre = pre->next 这种，因为指向关系已经改变了
            cur = rear; //用原先已经存储的变量的值来实现值的更替
        }
        // 因为空表的情况下，pre指向的是虚拟头节点，此时返回的头指针应为nullptr，故作此改变
        head = (pre != dummyHead ? pre : nullptr); //这条语句主要用于区分空表与非空表之间的头节点差异
        delete dummyHead;
        return head;
    }
};

// 卡尔的双指针写法(即迭代法) 比我的更为精简 牛！
// 时间复杂度O(n) 空间复杂度O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* temp;
        while (cur) {
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};

// 参照双指针写法写出的递归方式 比较难于理解
// 时间复杂度O(n) 空间复杂度O(n)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return reverse(nullptr, head);
    }

    ListNode* reverse(ListNode* pre, ListNode* cur) {
        if (!cur) return pre;
        ListNode* temp = cur->next;
        cur->next = pre;
        return reverse(cur, temp);
    }
};
