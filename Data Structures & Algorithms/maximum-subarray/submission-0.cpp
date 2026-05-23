class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = -1e9;
        int total = 0;
        int n = nums.size();
        int max_el = -1e9;
        for (int i = 0; i < n; i++) {
            max_el = max(max_el, nums[i]);
            total += nums[i];
            if (total <= 0) {
                total = 0;
            }
            if (total != 0) {
                ans = max(ans, total);
            }
        }
        if (ans == -1e9) {
            return max_el;
        }
        return ans;
    }

};