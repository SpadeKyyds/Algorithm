#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jumpFloor(int number) {
        vector<int> dp(3, 0);
        dp[0] = 1, dp[1] = 2;
        if (number == 1) return dp[0];
        if (number == 2) return dp[1];
        for (int i = 2; i < number; ++i) {
            dp[2] = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = dp[2];
        }
        return dp[2];
    }
};