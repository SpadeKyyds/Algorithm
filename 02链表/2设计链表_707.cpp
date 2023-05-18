/**
 * 难度：中等
 * 设计链表的实现。您可以选择使用单链表或双链表。单链表中的节点应该具有两个属性：val 和 next。val 是当前节点的值，next 是指向下一个节点的指针/引用。如果要使用双向链表，则还需要一个属性 prev 以指示链表中的上一个节点。假设链表中的所有节点都是 0-index 的。

    在链表类中实现这些功能：

    get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
    addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
    addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
    addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val  的节点。如果 index 等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
    deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。
     

    示例：

    MyLinkedList linkedList = new MyLinkedList();
    linkedList.addAtHead(1);
    linkedList.addAtTail(3);
    linkedList.addAtIndex(1,2);   //链表变为1-> 2-> 3
    linkedList.get(1);            //返回2
    linkedList.deleteAtIndex(1);  //现在链表是1-> 3
    linkedList.get(1);            //返回3

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/design-linked-list
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int val) : val(val), next(nullptr) {};
    ListNode(int val, ListNode* next) : val(val), next(next) {};
};

class MyLinkedList {
public:
    MyLinkedList() {
        this->m_size = 0;
        this->m_dummyHead = new ListNode();
    }
    
    int get(int index) {
        ListNode* cur;
        if (index < 0 || (index >= m_size)) {
            return -1;
        } else {
            cur = m_dummyHead->next;
            while (index--) {
                cur = cur->next;
            }
            return cur->val;
        }
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
        // ++m_size; 这里切忌不要将链表长度增加，因为在addAtIndex函数里增加了！
    }
    
    void addAtTail(int val) {
        int index = m_size;
        addAtIndex(index, val);
        // ++m_size;
    }
    
    void addAtIndex(int index, int val) {
        ListNode* cur, *tar;
        if (index <= 0) {
            cur = new ListNode(val, m_dummyHead->next);
            m_dummyHead->next = cur;
        } else if (index > m_size) {
            return;
        } else {
            cur = m_dummyHead;
            while (index--) {
                cur = cur->next;
            }
            tar = new ListNode(val, cur->next);
            cur->next = tar;
        }
        ++m_size;
    }
    
    void deleteAtIndex(int index) {
        ListNode* pre, *tar;
        if (index >= 0 && index < m_size) { //这里中间是&& 而不是||
            pre = m_dummyHead;
            while (index--) {
                pre = pre->next;
            }
            tar = pre->next;
            pre->next = tar->next;
            delete tar;
            --m_size;
        } else {
            return;
        }
    }

    void printList() {
        int len = m_size;
        ListNode* cur = m_dummyHead->next;
        while (len--) {
            cout << cur->val << "-->";
            cur = cur->next;
        }
        cout << "nullptr" << endl;
    }

private:
    int m_size;
    ListNode* m_dummyHead;
};

int main() {
    MyLinkedList p;
    p.addAtHead(1);
    p.addAtTail(3);
    p.addAtIndex(1, 2);
    p.printList(); //应输出为1-->2-->3

    cout << p.get(1) << endl; //返回2
    p.deleteAtIndex(1);
    p.printList(); //现在链表应输出为：1-->3
    cout << p.get(1) << endl; //返回3

    return 0;
}