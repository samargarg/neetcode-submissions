#include <cstring>

class Solution {

    int dp[110][3];

    vector<int> nums_;

    int calc(int i, int loot) {
        if (i == -1) {
            return 0;
        }
        if (dp[i][loot] != -1) {
            return dp[i][loot];
        }
        int ans = calc(i-1, 0);
        if (!loot) {
            ans = max(ans, calc(i-1, 1));
        }

        if (loot) {
            ans += nums_[i];
        }
        
        return dp[i][loot] = ans;
    }

public:
    int rob(vector<int>& nums) {
        nums_ = nums;
        memset(dp, -1, sizeof(dp));
        return max(calc(nums.size()-1, 0), calc(nums.size()-1, 1));
    }
};

// 0 1 2 3

// dp[i, 0] = max(dp[i-1, 1], dp[i-1, 0])
// dp[i, 1] = max(dp[i-1, 0])