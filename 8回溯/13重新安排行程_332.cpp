/**
 * Hard
 * 
 * 给你一份航线列表 tickets ，其中 tickets[i] = [fromi, toi] 表示飞机出发和降落的机场地点。请你对该行程进行重新规划排序。

    所有这些机票都属于一个从 JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK 开始。如果存在多种有效的行程，请你按字典排序返回最小的行程组合。

    例如，行程 ["JFK", "LGA"] 与 ["JFK", "LGB"] 相比就更小，排序更靠前。
    假定所有机票至少存在一种合理的行程。且所有的机票 必须都用一次 且 只能用一次。

     

    示例 1：


    输入：tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
    输出：["JFK","MUC","LHR","SFO","SJC"]
    示例 2：


    输入：tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
    输出：["JFK","ATL","JFK","SFO","ATL","SFO"]
    解释：另一种有效的行程是 ["JFK","SFO","ATL","JFK","ATL","SFO"] ，但是它字典排序更大更靠后。
     

    提示：

    1 <= tickets.length <= 300
    tickets[i].length == 2
    fromi.length == 3
    toi.length == 3
    fromi 和 toi 由大写英文字母组成
    fromi != toi


    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/reconstruct-itinerary
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<string> result = {"JFK"};
    vector<string> path = {"JFK"};

public:
    void backTracking(vector<vector<string>>& tickets, vector<bool>& used, string from, int start, int end) {
        if (path.size() == tickets.size() + 1) {
            result = path;
            return;
        }
        for (int i = start; i < end; ++i) {
            if (used[i] == true) continue;
            if (tickets[i][0] == from) {
                string to = tickets[i][0];
                used[i] = true;
                path.push_back(to);
                backTracking(tickets, used, to, i + 1, end);
                if (result.size() == tickets.size()) return; 
                used[i] = false;
                path.pop_back();
                backTracking(tickets, used, to, i + 1, end);
                i = start;
            }
        }
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<bool> used(tickets.size(), false);
        sort(tickets.begin(), tickets.end());
        backTracking(tickets, used, "JFK", 0, tickets.size());    
        return result;
    }
};

void printTickets(vector<vector<string>> tickets) {
    for (auto iter = tickets.begin(); iter != tickets.end(); ++iter) {
        for (auto i = (*iter).begin(); i != (*iter).end(); ++i) {
            cout << *i << "  ";
        }
        cout << endl;
    }
}

int main() {
    Solution s;
    vector<vector<string>> tickets = {{"JFK", "KUL"}, {"JFK", "NRT"}, {"NRT", "JFK"}};
    sort(tickets.begin(), tickets.end());
    s.findItinerary(tickets);
    printTickets(tickets);
    return 0;
}