/**
 * Middle
 * 
 * 给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。

     

    示例 1：


    输入：n = 3
    输出：5
    示例 2：

    输入：n = 1
    输出：1
     

    提示：

    1 <= n <= 19

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/unique-binary-search-trees
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
using namespace std;

// dp[i]含义:i个节点的不同二叉搜索树的个数
// 时间复杂度O(n^2) 空间复杂度O(n)
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        // 外层的i保证着后续的dp[i]得到dp[i - 1]的支撑
        // 我总体思路想到了 但是卡在了第n个节点的树个数需要n-1个节点树的个数来获得 不知道如何得到 甚至想到二分的思路 从叶子节点开始累加
        // 这种思路讲道理应该可行 可提高算法的时间复杂度 但实现起来颇为麻烦 
        // 卡尔这里就很灵性 使用双层循环 内存循环以i为终止条件 可以按顺序获得dp[i]的值
        // 总结:dp数组写出来 然后用变量抽象一下 说不定就想到了使用双层循环来解决问题 尚需锻炼！
        for (int i = 1; i <= n; ++i) {
            // j代表着以哪个数为头节点进行计数 这个内存循环很牛逼！
            for (int j = 1; j <= i; ++j) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};