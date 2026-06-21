#include <bits/stdc++.h>
class Solution {
    int dp[110][110];
    int calc(int i, int j) {
        if (i == 0 && j == 0) {
            return 1;
        }
        if (i < 0 || j < 0) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = 0;
        if (i) {
            ans += calc(i-1, j);
        }
        if (j) {
            ans += calc(i, j-1);
        }
        return dp[i][j] = ans;
    }

public:
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));
        return calc(m-1, n-1);
    }
};
