#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int Fibonacci(int n) {
        // dp[n - 1] 代表斐波那契的第n项
        vector<int> dp(n, 1);
        if (n < 3) return 1;
        for (int i = 2; i < n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n - 1];
    }
};