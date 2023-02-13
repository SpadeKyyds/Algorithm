/**
 * Easy
 * 
 * 斐波那契数 （通常用 F(n) 表示）形成的序列称为 斐波那契数列 。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：

    F(0) = 0，F(1) = 1
    F(n) = F(n - 1) + F(n - 2)，其中 n > 1
    给定 n ，请计算 F(n) 。

     

    示例 1：

    输入：n = 2
    输出：1
    解释：F(2) = F(1) + F(0) = 1 + 0 = 1
    示例 2：

    输入：n = 3
    输出：2
    解释：F(3) = F(2) + F(1) = 1 + 1 = 2
    示例 3：

    输入：n = 4
    输出：3
    解释：F(4) = F(3) + F(2) = 2 + 1 = 3
     

    提示：

    0 <= n <= 30

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/fibonacci-number
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
using namespace std;

// 递归解法 时间复杂度O(n^2) 空间复杂度O(n)
// 递归的时间复杂度主要是要看 递归的调用次数以及递归里操作的次数
class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        else if (n == 1) return 1;
        else return fib(n - 1) + fib (n - 2);
    }
};

// 动态规划个人参考卡尔的五部曲 浓缩出了三部曲
// 1.确定dp数组 dp数组含义
// 2.确定状态转移方程 包括初始值
// 3.确定遍历顺序

// 解法2：动态规划
// 时间复杂度O(n)  空间复杂度O(n)
class Solution {
public:
    int fib(int n) {
        if (n < 2) return n;
        vector<int> dp(n + 1); //因为是从0开始的 而要获取第n个数 因此共有n+1个
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i < n + 1; ++i) {
            dp[i] = dp [i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

// 解法3：动态规划优化
// 时间复杂度O(n) 空间复杂度O(1)
class Solution {
public:
    int fib(int n) {
        if (n < 2) return n;
        vector<int> dp(2);
        int sum;
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i < n + 1; ++i) {
            sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return sum;
    }
};