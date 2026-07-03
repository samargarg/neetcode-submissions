class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = -1;
        int sum = 0;
        int ans = 1e9;
        while (start < n) {
            while (end+1 < n && sum < target) {
                end++;
                sum += nums[end];
            }
            if (sum >= target) {
                ans = min(ans, end-start+1);
            }
            if (end >= start) {
                sum -= nums[start];
            } else {
                end++;
            }
            start++;
        }
        if (ans == 1e9) {
            return 0;
        }
        return ans;
    }
};