#include <bits/stdc++.h>
class Solution {

    int dp[10010];

    vector<int> coins_;
    int calc(int c) {
        if (c == 0) {
            return 0;
        }
        if (dp[c] != -1) {
            return dp[c];
        }
        int ans = 1e9;
        for (int i = 0; i < coins_.size(); i++) {
            if (coins_[i] > c) {
                continue;
            }
            ans = min(ans, 1 + calc(c-coins_[i]));
        }
        dp[c] = ans;
        return ans;
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        sort(coins.begin(), coins.end());
        coins_ = coins;
        int ans = calc(amount);
        if (ans == 1e9) {
            return -1;
        } else {
            return ans;
        }
    }
};
