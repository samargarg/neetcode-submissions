#include <bits/stdc++.h>
class Solution {
    string a;
    string b;
    int dp[1010][1010];
    int calc(int i, int j) {
        if (j < 0) {
            return 1;
        }
        if (i < 0) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = 0;
        if (a[i] == b[j]) {
            ans += calc(i-1, j-1);
        }
        ans += calc(i-1, j);
        dp[i][j] = ans;
        return ans;
    }

public:
    int numDistinct(string s, string t) {
        a = s;
        b = t;
        memset(dp, -1, sizeof(dp));
        return calc(s.size()-1, t.size()-1);
    }
};
