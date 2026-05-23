class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        int ans = 0;
        int prod = 1;
        int min_negative_prod = -1e9;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                prod = 1;
                min_negative_prod = -1e9;
                continue;
            }
            prod *= nums[i];
            if (prod < 0) {
                min_negative_prod = max(min_negative_prod, prod);
                if (prod != min_negative_prod) {
                    ans = max(ans, prod/min_negative_prod);
                }
            } else {
                ans = max(ans, prod);
            }
        }
        return ans;
    }
};
