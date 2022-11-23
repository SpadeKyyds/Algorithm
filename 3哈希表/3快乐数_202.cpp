/**
 * 难度：简单
 * 编写一个算法来判断一个数 n 是不是快乐数。

    「快乐数」 定义为：

    对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
    然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
    如果这个过程 结果为 1，那么这个数就是快乐数。
    如果 n 是 快乐数 就返回 true ；不是，则返回 false 。

     

    示例 1：

    输入：n = 19
    输出：true
    解释：
    12 + 92 = 82
    82 + 22 = 68
    62 + 82 = 100
    12 + 02 + 02 = 1
    示例 2：

    输入：n = 2
    输出：false

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/happy-number
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

// 使用哈希集合 充分利用其不要求有序 且不允许元素重复出现的特性
class Solution {
public:
    int getSum(int n) {
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> set;
        int sum = 0;
        while(1) {
            sum = getSum(n);
            if (sum == 1) {
                return true;
            } else {
                // set.find(key) 若找到返回值的迭代器 未找到返回尾后迭代器
                if (set.find(sum) != set.end()) {
                    return false; //这个sum曾经出现过 说明进入了死循环 返回false
                }
                set.insert(sum);
                n = sum;
            }
        }
    }
};