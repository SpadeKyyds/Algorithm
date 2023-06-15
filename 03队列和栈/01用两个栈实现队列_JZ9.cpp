#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    // int pop() {
    //     int res;
    //     if (!stack2.empty()) {
    //         res = stack2.top();
    //         stack2.pop();
    //     } else {
    //         while (!stack1.empty()) {
    //             stack2.push(stack1.top());
    //             stack1.pop();
    //         }
    //         res = stack2.top();
    //         stack2.pop();
    //     }
    //     return res;
    // }

    // 优化版本
    int pop() {
        int res;
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        } 
        res = stack2.top();
        stack2.pop();
        return res;   
    }

private:
    stack<int> stack1; //用于处理入队
    stack<int> stack2; //用于处理出队
};