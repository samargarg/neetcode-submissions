#include <bits/stdc++.h>
class Solution {

    vector<int> nums_;

    int dp[110];

    int calc(int i) {
        if (i < 0) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        int answer = nums_[i] + calc(i-2);
        answer = max(answer, calc(i-1));
        dp[i] = answer;
        return answer;
    }


public:
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        nums_ = nums;
        return calc(nums.size()-1);
    }
};
