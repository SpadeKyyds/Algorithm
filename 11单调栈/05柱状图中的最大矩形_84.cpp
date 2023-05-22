/**
 * Hard
 * 
 * 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

    求在该柱状图中，能够勾勒出来的矩形的最大面积。

     

    示例 1:



    输入：heights = [2,1,5,6,2,3]
    输出：10
    解释：最大的矩形为图中红色区域，面积为 10
    示例 2：



    输入： heights = [2,4]
    输出： 4
     

    提示：

    1 <= heights.length <=105
    0 <= heights[i] <= 104

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/largest-rectangle-in-histogram
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 本题双指针法有难度 采用单调递减栈相对来说更加简单 
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        stack<int> st; //单调递减辅助栈
        int ans = 0;
        for (int i = 0; i < heights.size(); ++i) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int mid = st.top();
                st.pop();
                int left = st.top();
                int right = i;
                // 这里这个距离的使用很灵性 即使更大的元素弹出了 但是结合距离和当前柱子的高度即可 不需要前面的那些更高的柱子
                // 总体来说维持的是一个单调递减栈 由栈顶向栈底单调递减
                ans = max(ans, (right - left - 1) * heights[mid]);
            }
            st.push(i); //这里简化了写法 当前元素大于或者等于栈顶元素的时候 直接入栈即可
        }
        return ans;
    }
};

// 卡尔版本
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int result = 0;
        stack<int> st;
        heights.insert(heights.begin(), 0); // 数组头部加入元素0
        heights.push_back(0); // 数组尾部加入元素0
        st.push(0);

        // 第一个元素已经入栈，从下标1开始
        for (int i = 1; i < heights.size(); i++) {
            if (heights[i] > heights[st.top()]) { // 情况一
                st.push(i);
            } else if (heights[i] == heights[st.top()]) { // 情况二
                st.pop(); // 这个可以加，可以不加，效果一样，思路不同
                st.push(i);
            } else { // 情况三
                while (!st.empty() && heights[i] < heights[st.top()]) { // 注意是while
                    int mid = st.top();
                    st.pop();
                    if (!st.empty()) {
                        int left = st.top();
                        int right = i;
                        int w = right - left - 1;
                        int h = heights[mid];
                        result = max(result, w * h);
                    }
                }
                st.push(i);
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> height {2,1,5,6,2,3};
    cout << s.largestRectangleArea(height) << endl;
    return 0;
}