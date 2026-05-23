#include <bits/stdc++.h>
using namespace std;
class Solution {
    int dp[35];
    int calc(int i) {
        
        if (i < 0) {
            return 0;
        }
        if (i == 0) {
            return 1;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        int ans = 0;
        ans += calc(i-1);
        ans += calc(i-2);
        dp[i] = ans;
        return ans;
    }

public:
    int climbStairs(int n) {
        memset(dp, -1, sizeof(dp));
        return calc(n);
    }
};
