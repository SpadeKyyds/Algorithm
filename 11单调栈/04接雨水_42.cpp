/**
 * Hard
 * 
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

     

    示例 1：



    输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
    输出：6
    解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
    示例 2：

    输入：height = [4,2,0,3,2,5]
    输出：9
     

    提示：

    n == height.length
    1 <= n <= 2 * 104
    0 <= height[i] <= 105

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/trapping-rain-water
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// 单调栈解法
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st; //记录柱子高度的下标
        int s = 0;
        for (int i = 0; i < height.size(); ++i) {
            if (st.empty() || height[i] <= height[st.top()]) {
                st.push(i);
            }
            else {
                while (!st.empty() && height[i] > height[st.top()]) {
                    int mid = height[st.top()];
                    st.pop();
                    if (!st.empty()) {
                        int length = i - st.top() - 1;
                        s += length * (min({height[i], height[st.top()]}) - mid);
                    } else {
                        break;
                    }
                }
                st.push(i);
            }
        }
        return s;
    }
};

// 双指针解法
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, leftMax = 0, rightMax = 0;
        int left = 0, right = height.size() - 1;
        // 为什么要用双指针不停地更新左右阈值呢？
        // 因为左右最大值是会改变的
        // 如果不用双指针 设从左端开始遍历 右端的最大值始终固定
        // 假设右端的左边几个柱子更高 那么更左端一点的可接雨水量应该依据最新的最高柱子判断 而不是最右端的柱子
        while (left < right) { //这里取<还是<=都是一样的 如果取到= 那么最后的Max值一定是在当前柱子上取得的 这样ans得到的是0 和不取=是一样的
            leftMax = max({leftMax, height[left]});
            rightMax = max({rightMax, height[right]});
            if (leftMax < rightMax) {
                ans += leftMax - height[left];
                ++left;
            } else {
                ans += rightMax - height[right];
                --right;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> heigh{0,1,0,2,1,0,1,3,2,1,2,1};
    cout << s.trap(heigh) << endl;
    return 0;
}