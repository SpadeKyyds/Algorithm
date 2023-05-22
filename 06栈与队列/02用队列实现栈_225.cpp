/**
 * 难度：简单
 * 请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。

    实现 MyStack 类：

    void push(int x) 将元素 x 压入栈顶。
    int pop() 移除并返回栈顶元素。
    int top() 返回栈顶元素。
    boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。
     

    注意：

    你只能使用队列的基本操作 —— 也就是 push to back、peek/pop from front、size 和 is empty 这些操作。
    你所使用的语言也许不支持队列。 你可以使用 list （列表）或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
     

    示例：

    输入：
    ["MyStack", "push", "push", "top", "pop", "empty"]
    [[], [1], [2], [], [], []]
    输出：
    [null, null, null, 2, 2, false]

    解释：
    MyStack myStack = new MyStack();
    myStack.push(1);
    myStack.push(2);
    myStack.top(); // 返回 2
    myStack.pop(); // 返回 2
    myStack.empty(); // 返回 False

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/implement-stack-using-queues
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
using namespace std;

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

// two queues realized stack
class MyStack {
private:
    queue<int> inQueue, outQueue;

public:
    MyStack() {

    }
    
    void push(int x) {
        inQueue.push(x);
    }
    
    int pop() {
        int result;
        while (inQueue.size() != 1) {
            outQueue.push(inQueue.front());
            inQueue.pop();
        }
        result = inQueue.front();
        inQueue.pop();

        while (!outQueue.empty()) {
            inQueue.push(outQueue.front());
            outQueue.pop();
        }
        return result;
    }
    
    int top() {
        int result;
        result = this->pop();
        inQueue.push(result);
        return result;
    }
    
    bool empty() {
        return outQueue.empty() && inQueue.empty();
    }
};

// single queue realized stack
// more memory space saved
class MyStack {
private:
    queue<int> singleQueue;

public:
    MyStack() {}

    void push(int x) {
        singleQueue.push(x);
    }

    int pop() {
        int result;
        // target pop elements num is total size subtract one
        int num = singleQueue.size() - 1;
        while(num--) {
            singleQueue.push(singleQueue.front());
            singleQueue.pop();
        }
        result = singleQueue.front();
        singleQueue.pop();
        return result;
    }

    int top() {
        int result;
        result = this->pop();
        singleQueue.push(result);
        return result;
    }

    bool empty() {
        return singleQueue.empty();
    }
};