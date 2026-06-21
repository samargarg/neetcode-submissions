#include <bits/stdc++.h>
class Solution {

    vector<int> nums_;

    int dp[110][3][3];

    int calc(int i, int steal, int last) {
        if (i == 0) {
            if (!last && steal) {
                return nums_[0];
            } else {
                return 0;
            }
        }
        if (dp[i][steal][last] != -1) {
            return dp[i][steal][last];
        }
        int ans = calc(i-1, 0, last);
        if (!steal) {
            ans = max(ans, calc(i-1, 1, last));
        }
        if (steal) {
            ans += nums_[i];
        }
        return dp[i][steal][last] = ans;
    }

public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        memset(dp, -1, sizeof(dp));
        nums_ = nums;
        return max(calc(nums.size()-1, 0, 0), calc(nums.size()-1, 1, 1));
    }
};
