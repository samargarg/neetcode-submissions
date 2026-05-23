#include <bits/stdc++.h>
class Solution {

    vector<int> nums_;

    int dp[110][3];

    int calc(int i, int last) {
        if (i < last) {
            return 0;
        }
        if (dp[i][last] != -1) {
            return dp[i][last];
        }
        int answer = nums_[i] + calc(i-2, last);
        answer = max(answer, calc(i-1, last));
        dp[i][last] = answer;
        return answer;
    }


public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        memset(dp, -1, sizeof(dp));
        nums_ = nums;
        int ans = calc(n-2, 0);
        int nex = nums[nums.size()-1];
        if (n >= 3) {
           nex += calc(nums.size()-3, 1);
        }
        ans = max(ans,  nex);
        return ans;
    }
};
