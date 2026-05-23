#include <bits/stdc++.h>
class Solution {
    
    int dp[10100];
    vector<int> nums_;

    int calc(int i) {
        if (i == nums_.size()-1) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        int ans = 1e9;
        for (int j = 1; j <= nums_[i]; j++) {
            if (i+j == nums_.size()) {
                break;
            }
            ans = min(ans, 1+calc(i+j));
        }
        dp[i] = ans;
        return ans;
    }


public:
    int jump(vector<int>& nums) {
        nums_ = nums;
        memset(dp, -1, sizeof(dp));
        return calc(0);
    }
};