/**
 * Middle
 * 
 * 假设有打乱顺序的一群人站成一个队列，数组 people 表示队列中一些人的属性（不一定按顺序）。每个 people[i] = [hi, ki] 表示第 i 个人的身高为 hi ，前面 正好 有 ki 个身高大于或等于 hi 的人。

    请你重新构造并返回输入数组 people 所表示的队列。返回的队列应该格式化为数组 queue ，其中 queue[j] = [hj, kj] 是队列中第 j 个人的属性（queue[0] 是排在队列前面的人）。

     

    示例 1：

    输入：people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
    输出：[[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
    解释：
    编号为 0 的人身高为 5 ，没有身高更高或者相同的人排在他前面。
    编号为 1 的人身高为 7 ，没有身高更高或者相同的人排在他前面。
    编号为 2 的人身高为 5 ，有 2 个身高更高或者相同的人排在他前面，即编号为 0 和 1 的人。
    编号为 3 的人身高为 6 ，有 1 个身高更高或者相同的人排在他前面，即编号为 1 的人。
    编号为 4 的人身高为 4 ，有 4 个身高更高或者相同的人排在他前面，即编号为 0、1、2、3 的人。
    编号为 5 的人身高为 7 ，有 1 个身高更高或者相同的人排在他前面，即编号为 1 的人。
    因此 [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]] 是重新构造后的队列。
    示例 2：

    输入：people = [[6,0],[5,0],[4,0],[3,2],[2,2],[1,4]]
    输出：[[4,0],[5,0],[2,2],[3,2],[1,4],[6,0]]
     

    提示：

    1 <= people.length <= 2000
    0 <= hi <= 106
    0 <= ki < people.length
    题目数据确保队列可以被重建


    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/queue-reconstruction-by-height
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

// 利用vector的insert来完成队列的构建 时间复杂度O(nlogn + n^2) 效率较低
// 首先按照身高降序排序 身高相同的按照当前人前面人数进行升序排序
// 最后以 当前人前面人数为数组下标进行数组构建
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        else return a[0] > b[0];
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> queue;
        for (int i = 0; i < people.size(); ++i) {
            queue.insert(queue.begin() + people[i][1], people[i]);
        }
        return queue;
    }
};

// 版本二：利用链表 节省时间开销的做法
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        else return a[0] > b[0];
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        list<vector<int>> que;
        for (int i = 0; i < people.size(); ++i) {
            int position = people[i][1];
            std::list<vector<int>>::iterator it = que.begin();
            while (position--) ++it; //这里用这种方式寻找插入位置 是因为两个容器的迭代器类型不同
            que.insert(it, people[i]);
        }
        return vector<vector<int>> (que.begin(), que.end()); //最后容器类型强制转换 满足函数返回值类型
    }
};