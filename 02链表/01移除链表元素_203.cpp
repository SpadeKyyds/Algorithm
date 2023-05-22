/**
 * 难度：简单
 * 给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
     

    示例 1：


    输入：head = [1,2,6,3,4,5,6], val = 6
    输出：[1,2,3,4,5]
    示例 2：

    输入：head = [], val = 1
    输出：[]
    示例 3：

    输入：head = [7,7,7,7], val = 7
    输出：[]

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/remove-linked-list-elements
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// 这一题我写的非常好，直接就是最完美版本，跟卡尔的代码对比没有一点多余！
// 事实证明基础不错，但熟练度不够，需要花费时间提高训练量，如此便会很叼！
#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    // 这种链表节点的构造方式需要掌握
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* prior;
        ListNode* target;
        // 对头结点的删除 
        while (head && head->val == val) {
            target = head;
            head = head->next;
            delete target;
        }
        // 要删除的节点不为头结点
        prior = head;
        while (prior && prior->next) {
            target = prior->next;
            if (target->val == val) {
                prior->next = target->next; //这里前面是prior->next 画图时数据域指针域都要画，避免此类错误
                delete target;
            } else {
                prior = prior->next;
            }
        }
        return head;
    }
};

class Solution1 {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* prior;
        ListNode* target;
        // 定义一个虚拟头结点 从而将所有情况都归为一类
        ListNode* dummyHead = new ListNode(0, head);
        prior = dummyHead;
        while (prior && prior->next) {
            target = prior->next;
            if (target->val == val) {
                prior->next = target->next;
                delete target;
            } else {
                prior = prior->next;
            }
        }
        head = dummyHead->next;
        delete dummyHead; //这里记得删除虚拟头结点
        return head;
    }
};

int main() {
    return 0;
}