/**
 * Middle
 * 
 * 给定一个区间的集合 intervals ，其中 intervals[i] = [starti, endi] 。返回 需要移除区间的最小数量，使剩余区间互不重叠 。

     

    示例 1:

    输入: intervals = [[1,2],[2,3],[3,4],[1,3]]
    输出: 1
    解释: 移除 [1,3] 后，剩下的区间没有重叠。
    示例 2:

    输入: intervals = [ [1,2], [1,2], [1,2] ]
    输出: 2
    解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。
    示例 3:

    输入: intervals = [ [1,2], [2,3] ]
    输出: 0
    解释: 你不需要移除任何区间，因为它们已经是无重叠的了。
     

    提示:

    1 <= intervals.length <= 105
    intervals[i].length == 2
    -5 * 104 <= starti < endi <= 5 * 104


    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/non-overlapping-intervals
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[0] < b[0]; //这里只对左区间进行排序即可 无需同时也对右区间排序
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int eraseNum = 0, end = intervals[0][1];
        // 题目中说明了intervals.size()最小为2
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < end) {
                ++eraseNum;
                // 这里当发生重叠的时候 要选择取右区间更小的区间段
                // 是基于已经排好序的区间段 贪心的精髓体现在此
                end = min(end, intervals[i][1]);
            } else end = max(end, intervals[i][1]);
        }
        return eraseNum;
    }
};