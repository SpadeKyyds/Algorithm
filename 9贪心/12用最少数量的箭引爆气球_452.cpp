/**
 * 
 * Middle
 * 
 * 有一些球形气球贴在一堵用 XY 平面表示的墙面上。墙面上的气球记录在整数数组 points ，其中points[i] = [xstart, xend] 表示水平直径在 xstart 和 xend之间的气球。你不知道气球的确切 y 坐标。

    一支弓箭可以沿着 x 轴从不同点 完全垂直 地射出。在坐标 x 处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend， 且满足  xstart ≤ x ≤ xend，则该气球会被 引爆 。可以射出的弓箭的数量 没有限制 。 弓箭一旦被射出之后，可以无限地前进。

    给你一个数组 points ，返回引爆所有气球所必须射出的 最小 弓箭数 。

     
    示例 1：

    输入：points = [[10,16],[2,8],[1,6],[7,12]]
    输出：2
    解释：气球可以用2支箭来爆破:
    -在x = 6处射出箭，击破气球[2,8]和[1,6]。
    -在x = 11处发射箭，击破气球[10,16]和[7,12]。
    示例 2：

    输入：points = [[1,2],[3,4],[5,6],[7,8]]
    输出：4
    解释：每个气球需要射出一支箭，总共需要4支箭。
    示例 3：

    输入：points = [[1,2],[2,3],[3,4],[4,5]]
    输出：2
    解释：气球可以用2支箭来爆破:
    - 在x = 2处发射箭，击破气球[1,2]和[2,3]。
    - 在x = 4处射出箭，击破气球[3,4]和[4,5]。
     

    提示:

    1 <= points.length <= 105
    points[i].length == 2
    -231 <= xstart < xend <= 231 - 1

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/minimum-number-of-arrows-to-burst-balloons
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

// 牛逼！自己写出来了！
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        else return a[0] < b[0];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int arrow = 1, end = points[0][1];
        // 题目中说明了points.size()最小为2
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] > end) { //不能重叠 启动下一支箭
                ++arrow;
                end = points[i][1];
            }
            // 重叠了就更新最小右边界
            end = min(end, points[i][1]); //这里要同步更新end的值 其为较小值
        }
        return arrow;
    }
};