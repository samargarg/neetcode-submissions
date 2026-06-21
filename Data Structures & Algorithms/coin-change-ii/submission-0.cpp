#include <bits/stdc++.h>
class Solution {

    vector<int> coins_;

    int dp[110][5010];

    int calc(int i, int amt) {
        if (i == -1) {
            return amt == 0;
        }
        if (dp[i][amt] != -1) {
            return dp[i][amt];
        }
        int ans = calc(i-1, amt);
        if (amt >= coins_[i]) {
            ans += calc(i, amt-coins_[i]);
        }
        return dp[i][amt] = ans;
    }

public:
    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof(dp));
        coins_ = coins;
        return calc(coins.size()-1, amount);
    }
};
